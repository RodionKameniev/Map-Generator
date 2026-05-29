#include "City.h"

#include <iostream>
#include <queue>
#include <random>
#include <set>
#include <functional>
#include <memory>

#include "Map.h"

using namespace std;

queue<Position> start_of_streets;
set<pair<double, Position>> place_for_buildings;
vector<Position> end_of_streets;

// Constructor
City::City(
    const vector<Building_cluster>&
    buildings,

    const vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn,

    const vector<
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
    const vector<Building_cluster>&
    buildings,

    const vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn,

    const vector<
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
    const vector<
    Building_cluster
    >& buildings
) {
    this->buildings =
        buildings;
}

void City::
set_buildings_probability_to_spawn(
    const vector<
    Building_cluster_spawn
    >& buildings_probability_to_spawn
) {
    this->buildings_probability_to_spawn =
        buildings_probability_to_spawn;
}

void City::
set_streets_probability_to_spawn(
    const vector<
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
const vector<
    Building_cluster
>&
City::get_buildings() const {
    return this->buildings;
}

const vector<
    Building_cluster_spawn
>&
City::
get_buildings_probability_to_spawn() const {
    return this->buildings_probability_to_spawn;
}

const vector<
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

//Street_cluster transform_street_cluster(
//    const Street_cluster& street_cluster,
//    int sx,
//    int sy
//)
//{
//    Street_cluster copy_cluster = street_cluster;
//
//    for (auto& component : copy_cluster.get_street_components())
//    {
//        Position pos = component.get_shifted_position();
//
//        int x = pos.get_on_x();
//        int y = pos.get_on_y();
//
//        // correct transformation
//        pos.set_on_x(x * sx);
//        pos.set_on_y(y * sy);
//
//        component.set_shifted_position(pos);
//    }
//
//    return copy_cluster;
//}
//
//
//vector<Street_cluster_spawn>
//create_all_vars_of_street(
//    const Street_cluster_spawn& street_spawn
//)
//{
//    vector<Street_cluster_spawn> all_vars;
//    set<string> used;
//
//    auto try_add = [&](Street_cluster cluster)
//        {
//            Street_cluster_spawn spawn(
//                std::make_shared<Street_cluster>(cluster),
//                street_spawn.get_probability_to_spawn()
//            );
//
//            string signature = std::create_signature(spawn);
//
//            if (used.insert(signature).second)
//            {
//                all_vars.push_back(spawn);
//            }
//        };
//
//    const Street_cluster& original =
//        *street_spawn.get_street();
//
//    try_add(original);
//
//    // 90°
//    try_add(transform_street_cluster(original, -1, 1));
//
//    // 180°
//    try_add(transform_street_cluster(original, -1, -1));
//
//    // 270°
//    try_add(transform_street_cluster(original, 1, -1));
//
//    return all_vars;
//}

void City::create_streets(Map& map) {
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

        vector<Street_cluster_spawn> candidates = this->get_streets_probability_to_spawn();

        bool is_chosen = false;
        Street_cluster_spawn chosen = candidates[0];

        while(!candidates.empty() && !is_chosen) {

            vector<float> weights;

            for(const auto& s :candidates) {
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
        if (is_chosen){
            chosen.build_street(map, current_start_of_street);
            vector<Position> next_start_of_streets = chosen.create_next_street_pos(current_start_of_street);
            for (int i = 0; i < next_start_of_streets.size(); i++) {
                start_of_streets.push(next_start_of_streets[i]);
            }
            set<pair<double, Position>> places = chosen.get_places_for_building(map, current_start_of_street, this->get_center_of_city());
            for (auto& el : places) {
                place_for_buildings.insert(el);
            }
            int cost_to_built_street = 0;
            for (int k = 0; k < chosen.get_street()->get_street_components().size(); k++) {
                cost_to_built_street += chosen.get_street()->get_street_components()[k].get_street_part()->get_cost_to_build();
            }
            this->set_cost(this->get_cost() + cost_to_built_street);
        }
        
    }
}
void City::create_buildings(Map& map) {
    random_device rd;

    mt19937 gen(rd());
    for(auto& current_place : place_for_buildings){

        vector<Building_cluster_spawn> candidates = this->get_buildings_probability_to_spawn();

        bool is_chosen = false;

        Building_cluster_spawn chosen = candidates[0];

        while (!candidates.empty() && !is_chosen) {

            vector<float> weights;

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
        if (is_chosen) {
           chosen.build_building(map, current_place.second);
           vector<Building_cluster> build = this->get_buildings();
           build.push_back(*chosen.get_building());
           this->set_buildings(build);
        }
    }
}

void City::create_city(Map& map) {
    this->create_streets(map);
    this->create_buildings(map);
    calculate_cost();
}

void City::calculate_cost() {
    int tot_cost_of_buildings = 0;
    for (int i = 0; i < this->get_buildings().size(); i++) {
        tot_cost_of_buildings += this->get_buildings()[i].get_cost_of_building();
    }
    this->set_cost(this->get_cost() + tot_cost_of_buildings);
}