#pragma once
#include <iostream>
#include <vector>

#include "Clutter_component.h"

class Clutter_cluster {
protected:
    std::vector<Clutter_component> clutter_components;
    float base_probability_to_spawn;

public:
    Clutter_cluster(
        const std::vector<Clutter_component>& clutters,
        const float base_probability_to_spawn
    )
        :
        clutter_components(clutter_components),
        base_probability_to_spawn(
            base_probability_to_spawn
        )
    {
        cout << "Clutter_cluster is called"
            << endl;
    }

    // Set functions
    void set(
        const std::vector<Clutter_component>& clutter_components,
        const float base_probability_to_spawn
    ) {
        this->clutter_components =
            clutter_components;

        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    void set_clutter_components(
        const std::vector<Clutter_component>& clutter_components
    ) {
        this->clutter_components =
            clutter_components;
    }

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const std::vector<Clutter_component>&
        get_clutter_components() const {
        return this->clutter_components;
    }

    const float get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
};