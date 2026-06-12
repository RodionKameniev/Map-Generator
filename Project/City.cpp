#include "City.h"

#include <iostream>
#include <queue>
#include <random>
#include <set>

#include "Rotation.h"
#include "Map.h"

using namespace std;

queue<Position> start_of_streets;
set<pair<double, Position>> place_for_buildings;
std::vector<Position> end_of_streets;

std::vector<std::vector<Street_cluster_spawn>> var_of_street_clusters;

std::vector<std::vector<Building_cluster_spawn>> var_of_building_clusters;

// Constructor
City::City(
    const std::vector<Building_cluster>&
    buildings,

    const std::vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn,

    const std::vector<
    Street_cluster_spawn
    >& streets_probability_to_spawn,

    const Parameters_for_city&
    parameters,

    int cost,

    const Position&
    center_of_city
)
    :
    buildings(buildings),

    buildings_probability_to_spawn(
        buildings_probability_to_spawn
    ),

    streets_probability_to_spawn(
        streets_probability_to_spawn
    ),

    parameters(parameters),

    cost(cost),

    center_of_city(center_of_city)
{
    cout << "City is called"
        << endl;
}

// Set functions
void City::set_all(
    const std::vector<Building_cluster>&
    buildings,

    const std::vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn,

    const std::vector<
    Street_cluster_spawn
    >& streets_probability_to_spawn,

    const Parameters_for_city&
    parameters,

    int cost,

    const Position&
    center_of_city
) {

    this->buildings =
        buildings;

    this->buildings_probability_to_spawn =
        buildings_probability_to_spawn;

    this->streets_probability_to_spawn =
        streets_probability_to_spawn;

    this->parameters =
        parameters;

    this->cost =
        cost;

    this->center_of_city =
        center_of_city;
}

void City::set_buildings(
    const std::vector<
    Building_cluster
    >& buildings
) {
    this->buildings =
        buildings;
}

void City::
set_buildings_probability_to_spawn(
    const std::vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn
) {
    this->buildings_probability_to_spawn =
        buildings_probability_to_spawn;
}

void City::
set_streets_probability_to_spawn(
    const std::vector<
    Street_cluster_spawn
    >& streets_probability_to_spawn
) {
    this->streets_probability_to_spawn =
        streets_probability_to_spawn;
}

void City::set_parameters(
    const Parameters_for_city&
    parameters
) {
    this->parameters =
        parameters;
}

void City::set_cost(
    int cost
) {
    this->cost =
        cost;
}

void City::set_center_of_city(
    const Position&
    center_of_city
) {
    this->center_of_city =
        center_of_city;
}

// Get functions
const std::vector<
    Building_cluster
>&
City::get_buildings() const {
    return this->buildings;
}

const std::vector<
    Building_cluster_spawn
>&
City::
get_buildings_probability_to_spawn() const {
    return this->buildings_probability_to_spawn;
}

const std::vector<
    Street_cluster_spawn
>&
City::
get_streets_probability_to_spawn() const {
    return this->streets_probability_to_spawn;
}

const Parameters_for_city&
City::get_parameters() const {
    return this->parameters;
}

int City::get_cost() const {
    return this->cost;
}

const Position&
City::get_center_of_city() const {
    return this->center_of_city;
}

// Algorithms

Street_cluster_spawn transform_street_cluster(
    const Street_cluster_spawn& street_cluster,
    Rotation rotation
)
{
    Street_cluster* street_copy =
        new Street_cluster(*street_cluster.get_street());

    for (auto& component : street_copy->get_street_components()){
        component.set_shifted_position(rotate_position(component.get_shifted_position(),rotation));
    }

    for (auto& pos : street_copy->get_position_for_next_street()){
        Position pos_copy = rotate_position(pos, rotation);
        pos.set_all(pos_copy.get_on_x(), pos_copy.get_on_y(), pos_copy.get_on_z());
    }

    Street_cluster_spawn result(
        street_copy,
        street_cluster.get_probability_to_spawn()
    );

    return result;
}

std::vector<Street_cluster_spawn>create_all_vars_of_street(const Street_cluster_spawn& street_spawn){
    
    //std::cout << "Enters crate vars of streets\n";

    std::vector<Street_cluster_spawn> all_vars;

    //Original
    all_vars.push_back(street_spawn);
    
    //90deg
    all_vars.push_back(transform_street_cluster(street_spawn, Rotation::Deg90));

    //180deg
    all_vars.push_back(transform_street_cluster(street_spawn,Rotation::Deg180));

    //270deg
    all_vars.push_back(transform_street_cluster(street_spawn, Rotation::Deg270));

    //std::cout << "Finishes crate vars of streets\n";

    return all_vars;
}


Building_cluster_spawn transform_building_cluster(const Building_cluster_spawn& building_cluster, Rotation rotation){
    Building_cluster* building_copy = new Building_cluster(*building_cluster.get_building());

    for (auto& component : building_copy->get_building_components()) {
        component.set_shifted_position(rotate_position(component.get_shifted_position(), rotation));
    }

    Building_cluster_spawn result(building_copy, building_cluster.get_probability_to_spawn());

    return result;
}

std::vector<Building_cluster_spawn>create_all_vars_of_building(const Building_cluster_spawn& building_spawn) {
    std::vector<Building_cluster_spawn> all_vars;

    //Original
    all_vars.push_back(building_spawn);

    //90deg
    all_vars.push_back(transform_building_cluster(building_spawn, Rotation::Deg90));

    //180deg
    all_vars.push_back(transform_building_cluster(building_spawn, Rotation::Deg180));

    //270deg
    all_vars.push_back(transform_building_cluster(building_spawn, Rotation::Deg270));

    return all_vars;
}

void City::create_streets(Map& map) {

    //std::cout << "All types creation\n";

    for (int l = 0; l < this->get_streets_probability_to_spawn().size(); l++) {
        var_of_street_clusters.push_back(create_all_vars_of_street(this->get_streets_probability_to_spawn()[l]));
    }
    //int p = 0;
    //int g = 0;
    //for (const auto& a : var_of_street_clusters) {
    //    std::cout << "var " << p << std::endl;
    //    p++;
    //    for (const auto& b : a) {
    //        std::cout << "var street " << g << std::endl;
    //        g++;
    //        for (const auto& c : b.get_street()->get_street_components()) {
    //            std::cout << "pos x: " << c.get_shifted_position().get_on_x()<< " pos y: " << c.get_shifted_position().get_on_y() << " pos z: " << c.get_shifted_position().get_on_z() << std::endl;
    //        }
    //    }
    //    g = 0;
    //}

    //int p = 0;
    //int g = 0;
    //std::cout << "var size" << var_of_street_clusters.size() << std::endl;
    //for (const auto& a : var_of_street_clusters) {
    //    std::cout << "street vars size" << a.size() << std::endl;
    //    p++;
    //    for (const auto& b : a) {
    //        std::cout << "street size" << b.get_street()->get_street_components().size()<< std::endl;
    //        g++;
    //        //for (const auto& c : b.get_street()->get_position_for_next_street()) {
    //        //    std::cout << "pos x: " << c.get_on_x() << " pos y: " << c.get_on_y() << " pos z: " << c.get_on_z() << std::endl;
    //        //}
    //    }
    //    g = 0;
    //}


    //std::cout << "All types creation completed\n";

    random_device rd;

    mt19937 gen(rd());

    //std::cout << "Start of streets entering\n";

    start_of_streets.push(this->get_center_of_city());

    //std::cout << "Start_placing\n";
    int comp = 0;

    while (start_of_streets.size() != 0) {
        //std::cout << "start_of_streets size: " << start_of_streets.size() << std::endl;
        //
        //std::cout << "Component: " << comp<<std::endl;
        //comp++;

        Position current_start_of_street = start_of_streets.front();

        start_of_streets.pop();

        if ((current_start_of_street.get_on_x() > this->center_of_city.get_on_x() + this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_start_of_street.get_on_x() < this->center_of_city.get_on_x() - this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_start_of_street.get_on_y() > this->center_of_city.get_on_y() + this->get_parameters().get_for_mini_map().get_size_y() / 2)
            || (current_start_of_street.get_on_y() < this->center_of_city.get_on_y() - this->get_parameters().get_for_mini_map().get_size_y() / 2)) {
           /* std::cout << "added to end_of_street: pos x: " << current_start_of_street.get_on_x() << " pos y : " << current_start_of_street.get_on_y() << " pos z : " << current_start_of_street.get_on_z() << std::endl;*/
            end_of_streets.push_back(current_start_of_street);
            continue;
        }

        std::vector<std::vector<Street_cluster_spawn>> candidates_var = var_of_street_clusters;

        std::vector<Street_cluster_spawn> chosen_var = candidates_var[0];

        bool is_chosen = false;

        Street_cluster_spawn chosen = candidates_var[0][0];
        

        while (!candidates_var.empty() && !is_chosen) {

            std::vector<float> weights_var;

            for (const auto& s : candidates_var) {
                weights_var.push_back(s[0].get_probability_to_spawn());
            }

            discrete_distribution<> dist(weights_var.begin(), weights_var.end());

            int index_var = dist(gen);

            //std::cout << "Chosen canditates_var: " << index_var << std::endl;

            std::vector<Street_cluster_spawn> candidates = candidates_var[index_var];

            chosen = candidates[0];

            while (!candidates.empty() && !is_chosen) {

                std::vector<float> weights;

                for (const auto& s : candidates) {
                    weights.push_back(s.get_probability_to_spawn());
                }

                discrete_distribution<> dist(weights.begin(), weights.end());

                int index = dist(gen);

                //std::cout << "Chosen canditate: " << index << std::endl;

                chosen = candidates[index];

                is_chosen = chosen.try_to_build(map, current_start_of_street);

                //std::cout << "is_chosen: " << is_chosen;

                if (!is_chosen) {
                    candidates.erase(candidates.begin() + index);
                }
            }
            if (!is_chosen) {
                candidates_var.erase(candidates_var.begin() + index_var);
            }

        }
        if (is_chosen) {
            chosen.build_street(map, current_start_of_street);
            std::vector<Position> next_start_of_streets = chosen.create_next_street_pos(current_start_of_street);
            for (int i = 0; i < next_start_of_streets.size(); i++) {
                start_of_streets.push(next_start_of_streets[i]);
            }
            set<pair<double, Position>> places = chosen.get_places_for_building(map, current_start_of_street, this->get_center_of_city());
            for (auto& el : places) {
                place_for_buildings.insert(el);
            }
            std::cout << "Size of place_for_buildings: " << place_for_buildings.size() << std::endl;
        }
    }
}

void City::create_buildings(Map& map) {
    for (int l = 0; l < this->get_buildings_probability_to_spawn().size(); l++) {
        //std::cout << "hello! " << this->get_buildings_probability_to_spawn()[l].get_building()->get_building_components()[0].get_shifted_position().get_on_x() << std::endl;
        var_of_building_clusters.push_back(create_all_vars_of_building(this->get_buildings_probability_to_spawn()[l]));
    }


    int p = 0;
    int g = 0;
    for (const auto& a : var_of_building_clusters) {
        std::cout << "var " << p << std::endl;
        p++;
        for (const auto& b : a) {
            std::cout << "var street " << g << std::endl;
            g++;
            std::cout << "var street size " << b.get_building()->get_building_components().size() << std::endl;
            //for (const auto& c : b.get_building()->get_building_components()) {
            //    std::cout << "pos x: " << c.get_shifted_position().get_on_x()<< " pos y: " << c.get_shifted_position().get_on_y() << " pos z: " << c.get_shifted_position().get_on_z() << std::endl;
            //}
        }
        g = 0;
    }

    //int p = 0;
    //int g = 0;
    //std::cout << "var size" << var_of_building_clusters.size() << std::endl;
    //for (const auto& a : var_of_building_clusters) {
    //    std::cout << "building vars size " << a.size() << std::endl;
    //    p++;
    //    for (const auto& b : a) {
    //        std::cout << "building size " << b.get_building()->get_building_components().size()<< std::endl;
    //        g++;
    //        //for (const auto& c : b.get_street()->get_position_for_next_street()) {
    //        //    std::cout << "pos x: " << c.get_on_x() << " pos y: " << c.get_on_y() << " pos z: " << c.get_on_z() << std::endl;
    //        //}
    //    }
    //    g = 0;
    //}
    random_device rd;

    mt19937 gen(rd());
    for (auto& current_place : place_for_buildings) {

        if ((current_place.second.get_on_x() > this->center_of_city.get_on_x() + this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_place.second.get_on_x() < this->center_of_city.get_on_x() - this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_place.second.get_on_y() > this->center_of_city.get_on_y() + this->get_parameters().get_for_mini_map().get_size_y() / 2)
            || (current_place.second.get_on_y() < this->center_of_city.get_on_y() - this->get_parameters().get_for_mini_map().get_size_y() / 2)) {
            continue;
        }

        std::vector<std::vector<Building_cluster_spawn>> candidates_var = var_of_building_clusters;

        std::vector<Building_cluster_spawn> chosen_var = candidates_var[0];

        bool is_chosen = false;

        Building_cluster_spawn chosen = candidates_var[0][0];

        while (!candidates_var.empty() && !is_chosen) {

            std::vector<float> weights_var;

            for (const auto& s : candidates_var) {
                weights_var.push_back(s[0].get_probability_to_spawn());
            }

            discrete_distribution<> dist(weights_var.begin(), weights_var.end());

            int index_var = dist(gen);

            std::vector<Building_cluster_spawn> candidates = candidates_var[index_var];

            chosen = candidates[0];
            while (!candidates.empty() && !is_chosen) {

                std::vector<float> weights;

                for (const auto& s : candidates) {
                    weights.push_back(s.get_probability_to_spawn());
                }

                discrete_distribution<> dist(weights.begin(), weights.end());

                int index = dist(gen);

                chosen = candidates[index];

                is_chosen = chosen.try_to_build(map, current_place.second);

                if (!is_chosen) {
                    candidates.erase(candidates.begin() + index);
                }
            }
            if (!is_chosen) {
                candidates_var.erase(candidates_var.begin() + index_var);
            }
        }
        if (is_chosen){
            chosen.build_building(map, current_place.second);
        }
    }
}


void City::create_city(Map& map) {
    this->create_streets(map);
    this->create_buildings(map);
}