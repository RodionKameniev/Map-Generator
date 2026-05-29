#pragma once
#include <iostream>
#include <vector>

#include "Building_component.h"

class Building_cluster {
protected:
    std::vector<Building_component> building_components;
    int cost_of_building;
    float base_probability_to_spawn;

public:
    Building_cluster(
        const std::vector<Building_component>& buildings,
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
        std::cout << "Building_cluster is called"
            << std::endl;
    }

    // Set functions
    void set(
        const std::vector<Building_component>& building_components,
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

    void set_building_components(
        const std::vector<Building_component>& building_components
    ) {
        this->building_components =
            building_components;
    }

    void set_cost_of_building(
        const int cost_of_building
    ) {
        this->cost_of_building =
            cost_of_building;
    }

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const std::vector<Building_component>&
        get_building_components() const {
        return this->building_components;
    }

    const int get_cost_of_building() const {
        return this->cost_of_building;
    }

    const float get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
};