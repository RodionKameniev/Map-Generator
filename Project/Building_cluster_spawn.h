#include <iostream>
#include "Building_cluster.h"

using namespace std;

class Building_spawn {
protected:
    const Building_cluster* building;

    float probability_to_spawn;

public:
    Building_spawn(
        const Building_cluster* building,
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
        const Building_cluster* building,
        const float probability_to_spawn
    ) {
        this->building =
            building;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_building(
        const Building_cluster* building
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
    const Building_cluster*
        get_building() const {
        return this->building;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};