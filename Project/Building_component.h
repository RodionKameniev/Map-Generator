#pragma once
#include <iostream>

#include "Parameters_for_building.h"
#include "Position.h"

class Building_component {
protected:
    const Parameters_for_building* building_part;

    Position shifted_position;

public:
    Building_component(
        const Parameters_for_building* building_part,
        const Position& shifted_position
    )
        :
        building_part(building_part),
        shifted_position(shifted_position)
    {
        std::cout << "Building_component is called"
            << std::endl;
    }

    // Set functions
    void set(
        const Parameters_for_building* building_part,
        const Position& shifted_position
    ) {
        this->building_part =
            building_part;

        this->shifted_position =
            shifted_position;
    }

    void set_building_part(
        const Parameters_for_building* building_part
    ) {
        this->building_part =
            building_part;
    }

    void set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_building*
        get_building_part() const {
        return this->building_part;
    }

    const Position&
        get_shifted_position() const {
        return this->shifted_position;
    }
};