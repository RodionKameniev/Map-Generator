#pragma once
#include <iostream>
#include <vector>
#include "Parameters_for_street.h"
#include "Cell_on_map.h"
#include "Direction.h"

class Street_on_map : public Cell_on_map {
protected:
    const Parameters_for_street* street_to_be_placed;

    std::vector<Direction> direction_of_connections;

    float base_probability_to_spawn;

public:
    Street_on_map(
        const Position& position,
        const Parameters_for_street* street_to_be_placed,
        const std::vector<Direction>& direction_of_connections,
        const float base_probability_to_spawn
    )
        :
        Cell_on_map(
            position,
            Type_of_object::Street
        ),
        street_to_be_placed(street_to_be_placed),
        direction_of_connections(direction_of_connections),
        base_probability_to_spawn(base_probability_to_spawn)
    {
        std::cout << "Street_on_map is called" << std::endl;
    }

    // Set functions
    void set(
        Parameters_for_street* street_to_be_placed,
        const std::vector<Direction>& direction_of_connections,
        const float base_probability_to_spawn
    ) {
        this->street_to_be_placed =
            street_to_be_placed;

        this->direction_of_connections =
            direction_of_connections;

        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    void set_street_to_be_placed(
        Parameters_for_street* street_to_be_placed
    ) {
        this->street_to_be_placed =
            street_to_be_placed;
    }

    void set_direction_of_connections(
        const std::vector<Direction>& direction_of_connections
    ) {
        this->direction_of_connections =
            direction_of_connections;
    }

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const Parameters_for_street*
        get_street_to_be_placed() const {
        return this->street_to_be_placed;
    }

    const vector<Direction>&
        get_direction_of_connections() const {
        return this->direction_of_connections;
    }

    const float get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
};
