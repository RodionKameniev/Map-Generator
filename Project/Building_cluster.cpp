#include "Building_cluster.h"

#include <iostream>
#include <vector>

#include "Building_component.h"

using namespace std;


Building_cluster::Building_cluster(
    const vector<Building_component>& buildings,
    const int cost_of_building,
    const float base_probability_to_spawn
)
    :
    building_components(building_components),
    cost_of_building(cost_of_building),
    base_probability_to_spawn(
        base_probability_to_spawn
    )
{
    calculate_cost();

    cout << "Building_cluster is called"
        << endl;
}

// Set functions
void Building_cluster::set(
    const vector<Building_component>& building_components,
    const int cost_of_building,
    const float base_probability_to_spawn
) {
    this->building_components =
        building_components;

    this->cost_of_building =
        cost_of_building;

    this->base_probability_to_spawn =
        base_probability_to_spawn;
}

void Building_cluster::set_building_components(
    const vector<Building_component>& building_components
) {
    this->building_components =
        building_components;
}

void Building_cluster::set_cost_of_building(
    const int cost_of_building
) {
    this->cost_of_building =
        cost_of_building;
}

void Building_cluster::set_base_probability_to_spawn(
    const float base_probability_to_spawn
) {
    this->base_probability_to_spawn =
        base_probability_to_spawn;
}

// Get functions
const vector<Building_component>&
Building_cluster::get_building_components() const {
    return this->building_components;
}

const int Building_cluster::get_cost_of_building() const {
    return this->cost_of_building;
}

const float Building_cluster::get_base_probability_to_spawn() const {
    return this->base_probability_to_spawn;
}

void Building_cluster::calculate_cost() {
    int cost = 0;
    for (int i = 0; i < this->get_building_components().size(); i++) {
        cost += this->get_building_components()[i].get_building_part()->get_cost();
    }
    this->set_cost_of_building(this->get_cost_of_building() + cost);
}