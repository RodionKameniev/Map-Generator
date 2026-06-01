#include "Clutter_component.h"

#include <iostream>
#include "Parameters_for_clutter.h"
#include "Position.h"


Clutter_component::Clutter_component(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    )
        :
        clutter_part(clutter_part),
        shifted_position(shifted_position)
    {
        std::cout << "Clutter_component is called"
            << std::endl;
    }

    // Set functions
    void Clutter_component::set(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    ) {
        this->clutter_part =
            clutter_part;

        this->shifted_position =
            shifted_position;
    }

    void Clutter_component::set_clutter_part(
        const Parameters_for_clutter* clutter_part
    ) {
        this->clutter_part =
            clutter_part;
    }

    void Clutter_component::set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_clutter*
        Clutter_component::get_clutter_part() const {
        return this->clutter_part;
    }

    const Position&
        Clutter_component::get_shifted_position() const {
        return this->shifted_position;
    }
