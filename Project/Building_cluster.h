#pragma once
#include <iostream>
#include <vector>

#include "Building_component.h"

using namespace std;

class Building_cluster {
protected:
    vector<Building_component> building_components;
    int cost_of_building;
    float base_probability_to_spawn;

public:
    Building_cluster(
        const vector<Building_component>& buildings,
        const int cost_of_building,
        const float base_probability_to_spawn
    );

    // Set functions
    void set(
        const vector<Building_component>& building_components,
        const int cost_of_building,
        const float base_probability_to_spawn
    );

    void set_building_components(
        const vector<Building_component>& building_components
    );

    void set_cost_of_building(
        const int cost_of_building
    );

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    );

    // Get functions
    const vector<Building_component>&
        get_building_components() const;

    const int get_cost_of_building() const;

    const float get_base_probability_to_spawn() const;

    void calculate_cost();
};