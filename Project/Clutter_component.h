#pragma once
#include <iostream>
#include "Parameters_for_clutter.h"
#include "Position.h"

class Clutter_component {
protected:
    const Parameters_for_clutter* clutter_part;

    Position shifted_position;

public:
    Clutter_component(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    );

    // Set functions
    void set(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    );

    void set_clutter_part(
        const Parameters_for_clutter* clutter_part
    );

    void set_shifted_position(
        const Position& shifted_position
    );

    // Get functions
    const Parameters_for_clutter*
        get_clutter_part() const;

    const Position&
        get_shifted_position() const;
};
