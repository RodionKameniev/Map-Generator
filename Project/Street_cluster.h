#pragma once
#include <iostream>
#include <vector>

#include "Street_component.h"
#include "Position.h"

using namespace std;

class Street_cluster {
protected:
    vector<Street_component> street_components;

    vector<Position> position_for_next_street;

    float base_probability_to_spawn;

public:
    Street_cluster(
        const vector<Street_component>& streets,
        const vector<Position>& position_for_next_street,
        const float base_probability_to_spawn
    );

    // Set functions
    void set(
        const vector<Street_component>& street_components,
        const vector<Position>& position_for_next_street,
        const float base_probability_to_spawn
    );

    void set_street_components(
        const vector<Street_component>& street_components
    );

    void set_position_for_next_street(
        const vector<Position>&
        position_for_next_street
    );

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    );

    // Get functions
    const vector<Street_component>&
        get_street_components() const;

    vector<Street_component>&
        get_street_components();

    const vector<Position>&
        get_position_for_next_street() const;

    const float get_base_probability_to_spawn() const;
};