#include "Street_on_map.h"
#include <iostream>
#include <vector>
#include "Parameters_for_street.h"
#include "Cell_on_map.h"
#include "Direction.h"

Street_on_map::Street_on_map(
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
        //std::cout << "Street_on_map is called" << std::endl;
    }

    // Set functions
    void Street_on_map::set(
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

    void Street_on_map::set_street_to_be_placed(
        Parameters_for_street* street_to_be_placed
    ) {
        this->street_to_be_placed =
            street_to_be_placed;
    }

    void Street_on_map::set_direction_of_connections(
        const std::vector<Direction>& direction_of_connections
    ) {
        this->direction_of_connections =
            direction_of_connections;
    }

    void Street_on_map::set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions
    const Parameters_for_street*
        Street_on_map::get_street_to_be_placed() const {
        return this->street_to_be_placed;
    }

    const vector<Direction>&
        Street_on_map::get_direction_of_connections() const {
        return this->direction_of_connections;
    }

    const float Street_on_map::get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
