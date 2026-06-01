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
    );

    // Set functions
    void set(
        const std::vector<Clutter_component>& clutter_components,
        const float base_probability_to_spawn
    );

    void set_clutter_components(
        const std::vector<Clutter_component>& clutter_components
    );

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    );

    // Get functions
    const std::vector<Clutter_component>&
        get_clutter_components() const;

    const float get_base_probability_to_spawn() const;
};