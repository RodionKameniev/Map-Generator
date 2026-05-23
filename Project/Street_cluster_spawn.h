#include <iostream>
#include "Street_cluster.h"

using namespace std;

class Street_cluster_spawn {
protected:
    const Street_cluster* street;

    float probability_to_spawn;

public:
    Street_cluster_spawn(
        const Street_cluster* street,
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
        const Street_cluster* street,
        const float probability_to_spawn
    ) {
        this->street =
            street;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_street(
        const Street_cluster* street
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
    const Street_cluster*
        get_street() const {
        return this->street;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }
};