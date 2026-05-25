#include "City.h"

#include <iostream>
#include <queue>
#include <random>
#include <set>

#include "Map.h"

using namespace std;

queue<Position> start_of_streets;
set<pair<float, Position>> place_for_buildings;

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
void City::set(
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
void City::create_streets(
    Map& map
) {

    random_device rd;

    mt19937 gen(rd());

    while (start_of_streets.size() != 0) {

        Position current_start_of_street = start_of_streets.front();

        start_of_streets.pop();

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
        }
        
    }
}