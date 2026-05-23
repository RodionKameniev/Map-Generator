#include <iostream>
#include <vector>

#include "Street_component.h"
#include "Position.h"

using namespace std;

class Street_cluster {
protected:
    vector<Street_component> street_components;

    vector<Position> position_for_next_street;

    float base_probability_to_spawn;

public:
    Street_cluster(
        const vector<Street_component>& streets,
        const vector<Position>& position_for_next_street,
        const float base_probability_to_spawn
    )
        :
        street_components(street_components),
        position_for_next_street(
            position_for_next_street
        ),
        base_probability_to_spawn(
            base_probability_to_spawn
        )
    {
        cout << "Street_cluster is called"
            << endl;
    }

    // Set functions
    void set(
        const vector<Street_component>& street_components,
        const vector<Position>& position_for_next_street,
        const float base_probability_to_spawn
    ) {
        this->street_components =
            street_components;

        this->position_for_next_street =
            position_for_next_street;

        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    void set_street_components(
        const vector<Street_component>& street_components
    ) {
        this->street_components =
            street_components;
    }

    void set_position_for_next_street(
        const vector<Position>&
        position_for_next_street
    ) {
        this->position_for_next_street =
            position_for_next_street;
    }

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const vector<Street_component>&
        get_street_components() const {
        return this->street_components;
    }

    const vector<Position>&
        get_position_for_next_street() const {
        return this->position_for_next_street;
    }

    const float get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
};