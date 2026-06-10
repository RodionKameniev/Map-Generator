#include "Street_cluster.h"

#include <iostream>
#include <vector>

#include "Street_component.h"
#include "Position.h"

using namespace std;


Street_cluster::Street_cluster(
    const vector<Street_component>& streets,
    const vector<Position>& position_for_next_street,
    const float base_probability_to_spawn
)
    :
    street_components(streets),
    position_for_next_street(
        position_for_next_street
    ),
    base_probability_to_spawn(
        base_probability_to_spawn
    )
{
    cout << "Street_cluster is called"
        << endl;
}

// Set functions
void Street_cluster::set(
    const vector<Street_component>& street_components,
    const vector<Position>& position_for_next_street,
    const float base_probability_to_spawn
) {
    this->street_components =
        street_components;

    this->position_for_next_street =
        position_for_next_street;

    this->base_probability_to_spawn =
        base_probability_to_spawn;
}

void Street_cluster::set_street_components(
    const vector<Street_component>& street_components
) {
    this->street_components =
        street_components;
}

void Street_cluster::set_position_for_next_street(
    const vector<Position>&
    position_for_next_street
) {
    this->position_for_next_street =
        position_for_next_street;
}

void Street_cluster::set_base_probability_to_spawn(
    const float base_probability_to_spawn
) {
    this->base_probability_to_spawn =
        base_probability_to_spawn;
}

// Get functions
const vector<Street_component>&
Street_cluster::get_street_components() const {
    return this->street_components;
}

vector<Street_component>& Street_cluster::get_street_components() {
    return this->street_components;
}

const vector<Position>&
Street_cluster::get_position_for_next_street() const {
    return this->position_for_next_street;
}

vector<Position>& Street_cluster::get_position_for_next_street()
{
    return position_for_next_street;
}

const float Street_cluster::get_base_probability_to_spawn() const {
    return this->base_probability_to_spawn;
}