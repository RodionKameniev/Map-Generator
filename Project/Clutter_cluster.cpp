#include "Clutter_cluster.h"

#include <iostream>
#include <vector>

#include "Clutter_component.h"


Clutter_cluster::Clutter_cluster(
        const std::vector<Clutter_component>& clutters,
        const float base_probability_to_spawn
    )
        :
        clutter_components(clutter_components),
        base_probability_to_spawn(
            base_probability_to_spawn
        )
    {
        std::cout << "Clutter_cluster is called"
            << std::endl;
    }

    // Set functions
    void Clutter_cluster::set(
        const std::vector<Clutter_component>& clutter_components,
        const float base_probability_to_spawn
    ) {
        this->clutter_components =
            clutter_components;

        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    void Clutter_cluster::set_clutter_components(
        const std::vector<Clutter_component>& clutter_components
    ) {
        this->clutter_components =
            clutter_components;
    }

    void Clutter_cluster::set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const std::vector<Clutter_component>&
        Clutter_cluster::get_clutter_components() const {
        return this->clutter_components;
    }

    const float Clutter_cluster::get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }