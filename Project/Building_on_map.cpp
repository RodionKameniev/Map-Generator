#include "Building_on_map.h"

#include <iostream>
#include <vector>
#include "Parameters_for_building.h"
#include "Cell_on_map.h"
#include "Direction.h"
#include "Position.h"



Building_on_map::Building_on_map(
        const Position& position,
        const Parameters_for_building* building_to_be_placed,
        const Direction direction,
        const float base_probability_to_spawn
    )
        :
        Cell_on_map(
            position,
            Type_of_object::Building
        ),
        building_to_be_placed(building_to_be_placed),
        direction(direction),
        base_probability_to_spawn(base_probability_to_spawn)
    {
        std::cout << "Building_on_map is called" << std::endl;
    }

    // Set functions

    void Building_on_map::set(
        Parameters_for_building* building_to_be_placed,
        const Direction direction,
        const float base_probability_to_spawn
    ) {
        this->building_to_be_placed =
            building_to_be_placed;

        this->direction =
            direction;

        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    void Building_on_map::set_building_to_be_placed(
        Parameters_for_building* building_to_be_placed
    ) {
        this->building_to_be_placed =
            building_to_be_placed;
    }

    void Building_on_map::set_direction(
        const Direction direction
    ) {
        this->direction =
            direction;
    }

    void Building_on_map::set_base_probability_to_spawn(
        const float base_probability_to_spawn
    ) {
        this->base_probability_to_spawn =
            base_probability_to_spawn;
    }

    // Get functions

    const Parameters_for_building*
        Building_on_map::get_building_to_be_placed() const {
        return this->building_to_be_placed;
    }

    const Direction Building_on_map::get_direction() const {
        return this->direction;
    }

    const float Building_on_map::get_base_probability_to_spawn() const {
        return this->base_probability_to_spawn;
    }
