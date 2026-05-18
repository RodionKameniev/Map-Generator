#include <iostream>
#include "Parameters_for_building.h"

class Building_spawn {
protected:
    const Parameters_for_building* building;

    float probability_to_spawn;

public:
    Building_spawn(
        const Parameters_for_building* building,
        const float probability_to_spawn
    )
        :
        building(building),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Building_spawn is called" << endl;
    }

    // Set functions
    void set(
        const Parameters_for_building* building,
        const float probability_to_spawn
    ) {
        this->building =
            building;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_building(
        const Parameters_for_building* building
    ) {
        this->building =
            building;
    }

    void set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Parameters_for_building*
        get_building() const {
        return this->building;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};