#include "Clutter_cluster_spawn.h"

#include <iostream>
#include "Clutter_cluster.h"


Clutter_cluster_spawn::Clutter_cluster_spawn(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    )
        :
        clutter(clutter),
        probability_to_spawn(probability_to_spawn)
    {
        std::cout << "Clutter_cluster_spawn is called" << std::endl;
    }

    // Set functions
    void Clutter_cluster_spawn::set(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    ) {
        this->clutter =
            clutter;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void Clutter_cluster_spawn::set_clutter(
        const Clutter_cluster* clutter
    ) {
        this->clutter =
            clutter;
    }

    void Clutter_cluster_spawn::set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Clutter_cluster*
        Clutter_cluster_spawn::get_clutter() const {
        return this->clutter;
    }

    const float Clutter_cluster_spawn::get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }