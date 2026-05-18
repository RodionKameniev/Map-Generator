#include <iostream>
#include "Parameters_for_clutter.h"

class Clutter_spawn {
protected:
    const Parameters_for_clutter* clutter;

    float probability_to_spawn;

public:
    Clutter_spawn(
        const Parameters_for_clutter* clutter,
        const float probability_to_spawn
    )
        :
        clutter(clutter),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Clutter_spawn is called" << endl;
    }

    // Set functions
    void set(
        const Parameters_for_clutter* clutter,
        const float probability_to_spawn
    ) {
        this->clutter =
            clutter;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_clutter(
        const Parameters_for_clutter* clutter
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
    const Parameters_for_clutter*
        get_clutter() const {
        return this->clutter;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};