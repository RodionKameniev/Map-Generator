#include "Building_component.h"

#include <iostream>

#include "Parameters_for_building.h"
#include "Position.h"

    Building_component::Building_component(
        const Parameters_for_building* building_part,
        const Position& shifted_position
    )
        :
        building_part(building_part),
        shifted_position(shifted_position)
    {
        //std::cout << "Building_component is called" << std::endl;
    }

    // Set functions
    void Building_component::set(
        const Parameters_for_building* building_part,
        const Position& shifted_position
    ) {
        this->building_part =
            building_part;

        this->shifted_position =
            shifted_position;
    }

    void Building_component::set_building_part(
        const Parameters_for_building* building_part
    ) {
        this->building_part =
            building_part;
    }

    void Building_component::set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_building*
        Building_component::get_building_part() const {
        return this->building_part;
    }

    const Position&
        Building_component::get_shifted_position() const {
        return this->shifted_position;
    }