#include <iostream>
#include "Parameters_for_street.h"

class Street_spawn {
protected:
    const Parameters_for_street* street;

    float probability_to_spawn;

public:
    Street_spawn(
        const Parameters_for_street* street,
        const float probability_to_spawn
    )
        :
        street(street),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Street_spawn is called" << endl;
    }

    // Set functions
    void set(
        const Parameters_for_street* street,
        const float probability_to_spawn
    ) {
        this->street =
            street;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_street(
        const Parameters_for_street* street
    ) {
        this->street =
            street;
    }

    void set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Parameters_for_street*
        get_street() const {
        return this->street;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};