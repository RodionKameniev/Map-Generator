#pragma once
#include <iostream>
#include <vector>
#include "Parameters_for_building.h"
#include "Cell_on_map.h"
#include "Direction.h"
#include "Position.h"


class Building_on_map : public Cell_on_map {
protected:
    const Parameters_for_building* building_to_be_placed;

    Direction direction;

    float base_probability_to_spawn;

public:
    Building_on_map(
        const Position& position,
        const Parameters_for_building* building_to_be_placed,
        const Direction direction,
        const float base_probability_to_spawn
    );

    // Set functions

    void set(
        Parameters_for_building* building_to_be_placed,
        const Direction direction,
        const float base_probability_to_spawn
    );

    void set_building_to_be_placed(
        Parameters_for_building* building_to_be_placed
    );

    void set_direction(
        const Direction direction
    );

    void set_base_probability_to_spawn(
        const float base_probability_to_spawn
    );

    // Get functions

    const Parameters_for_building*
        get_building_to_be_placed() const;

    const Direction get_direction() const;

    const float get_base_probability_to_spawn() const;
};