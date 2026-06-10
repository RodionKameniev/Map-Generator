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

std::vector<vector<Street_cluster_spawn>> var_of_street_clusters;

std::vector<vector<Building_cluster_spawn>> var_of_building_clusters;

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
    std::vector<Street_cluster_spawn> all_vars;

    //Original
    all_vars.push_back(street_spawn);
    
    //90deg
    all_vars.push_back(transform_street_cluster(street_spawn, Rotation::Deg90));

    //180deg
    all_vars.push_back(transform_street_cluster(street_spawn,Rotation::Deg180));

    //270deg
    all_vars.push_back(transform_street_cluster(street_spawn, Rotation::Deg270));

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

    for (int l = 0; l <= this->get_streets_probability_to_spawn().size(); l++) {
        var_of_street_clusters.push_back(create_all_vars_of_street(this->get_streets_probability_to_spawn()[l]));
    }
    random_device rd;

    mt19937 gen(rd());

    start_of_streets.push(this->get_center_of_city());

    while (start_of_streets.size() != 0) {

        Position current_start_of_street = start_of_streets.front();

        start_of_streets.pop();

        if ((current_start_of_street.get_on_x() > this->center_of_city.get_on_x() + this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_start_of_street.get_on_x() < this->center_of_city.get_on_x() - this->get_parameters().get_for_mini_map().get_size_x() / 2)
            || (current_start_of_street.get_on_y() > this->center_of_city.get_on_y() + this->get_parameters().get_for_mini_map().get_size_y() / 2)
            || (current_start_of_street.get_on_y() < this->center_of_city.get_on_y() - this->get_parameters().get_for_mini_map().get_size_y() / 2)) {

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

            std::vector<Street_cluster_spawn> candidates = candidates_var[index_var];

            chosen = candidates[0];

            while (!candidates.empty() && !is_chosen) {

                std::vector<float> weights;

                for (const auto& s : candidates) {
                    weights.push_back(s.get_probability_to_spawn());
                }

                discrete_distribution<> dist(weights.begin(), weights.end());

                int index = dist(gen);

                chosen = candidates[index];

                is_chosen = chosen.try_to_build(map, current_start_of_street);

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
        }
    }
}



//void City::create_streets(Map& map) {
//
//    for (int l = 0; l <= this->get_streets_probability_to_spawn().size(); l++) {
//        var_of_street_clusters.push_back(create_all_vars_of_street(this->get_streets_probability_to_spawn()[l]));
//    }
//    random_device rd;
//
//    mt19937 gen(rd());
//
//    start_of_streets.push(this->get_center_of_city());
//
//    while (start_of_streets.size() != 0) {
//
//        Position current_start_of_street = start_of_streets.front();
//
//        start_of_streets.pop();
//        
//        if ((current_start_of_street.get_on_x() > this->center_of_city.get_on_x() + this->get_parameters().get_for_mini_map().get_size_x() / 2)
//            || (current_start_of_street.get_on_x() < this->center_of_city.get_on_x() - this->get_parameters().get_for_mini_map().get_size_x() / 2)
//            || (current_start_of_street.get_on_y() > this->center_of_city.get_on_y() + this->get_parameters().get_for_mini_map().get_size_y() / 2)
//            || (current_start_of_street.get_on_y() < this->center_of_city.get_on_y() - this->get_parameters().get_for_mini_map().get_size_y() / 2)) {
//
//            end_of_streets.push_back(current_start_of_street);
//            continue;
//        }
//
//        std::vector<Street_cluster_spawn> candidates = this->get_streets_probability_to_spawn(); //need to be changed
//
//        bool is_chosen = false;
//        Street_cluster_spawn chosen = candidates[0];
//
//        while(!candidates.empty() && !is_chosen) {
//
//            std::vector<float> weights;
//
//            for(const auto& s :candidates) {
//                weights.push_back(s.get_probability_to_spawn());
//            }
//
//            discrete_distribution<> dist(weights.begin(), weights.end());
//
//            int index = dist(gen);
//
//            chosen = candidates[index];
//
//            is_chosen = chosen.try_to_build(map, current_start_of_street);
//
//            if (!is_chosen) {
//                candidates.erase(candidates.begin() + index);
//            }
//        }
//        if (is_chosen){
//            chosen.build_street(map, current_start_of_street);
//            std::vector<Position> next_start_of_streets = chosen.create_next_street_pos(current_start_of_street);
//            for (int i = 0; i < next_start_of_streets.size(); i++) {
//                start_of_streets.push(next_start_of_streets[i]);
//            }
//            set<pair<double, Position>> places = chosen.get_places_for_building(map, current_start_of_street, this->get_center_of_city());
//            for (auto& el : places) {
//                place_for_buildings.insert(el);
//            }
//        }
//        
//    }
//}


void City::create_buildings(Map& map) {
    for (int l = 0; l <= this->get_buildings_probability_to_spawn().size(); l++) {
        var_of_building_clusters.push_back(create_all_vars_of_building(this->get_buildings_probability_to_spawn()[l]));
    }
    random_device rd;

    mt19937 gen(rd());
    for (auto& current_place : place_for_buildings) {

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

//void City::create_buildings(Map& map) {
//    random_device rd;
//
//    mt19937 gen(rd());
//    for(auto& current_place : place_for_buildings){
//
//        std::vector<Building_cluster_spawn> candidates = this->get_buildings_probability_to_spawn();
//
//        bool is_chosen = false;
//
//        Building_cluster_spawn chosen = candidates[0];
//
//        while (!candidates.empty() && !is_chosen) {
//
//            std::vector<float> weights;
//
//            for (const auto& s : candidates) {
//                weights.push_back(s.get_probability_to_spawn());
//            }
//
//            discrete_distribution<> dist(weights.begin(), weights.end());
//
//            int index = dist(gen);
//
//            chosen = candidates[index];
//
//            is_chosen = chosen.try_to_build(map, current_place.second);
//
//            if (!is_chosen) {
//                candidates.erase(candidates.begin() + index);
//            }
//        }
//        if (is_chosen) {
//           chosen.build_building(map, current_place.second);
//            
//        }
//    }
//}

void City::create_city(Map& map) {
    this->create_streets(map);
    this->create_buildings(map);
}