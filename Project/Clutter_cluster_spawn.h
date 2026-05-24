#include <iostream>
#include "Clutter_cluster.h"

class Clutter_cluster_spawn {
protected:
    const Clutter_cluster* clutter;

    float probability_to_spawn;

public:
    Clutter_cluster_spawn(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    )
        :
        clutter(clutter),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Clutter_cluster_spawn is called" << endl;
    }

    // Set functions
    void set(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    ) {
        this->clutter =
            clutter;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_clutter(
        const Clutter_cluster* clutter
    ) {
        this->clutter =
            clutter;
    }

    void set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Clutter_cluster*
        get_clutter() const {
        return this->clutter;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};