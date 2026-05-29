#pragma once
#include <iostream>
#include "Parameters_for_street.h"
#include "Position.h"

class Street_component {
protected:
    const Parameters_for_street* street_part;

    Position shifted_position;

public:
    Street_component(
        const Parameters_for_street* street_part,
        const Position& shifted_position
    );

    // Set functions
    void set(
        const Parameters_for_street* street_part,
        const Position& shifted_position
    );

    void set_street_part(
        const Parameters_for_street* street_part
    );

    void set_shifted_position(
        const Position& shifted_position
    );

    // Get functions
    const Parameters_for_street*
        get_street_part() const;

    const Position&
        get_shifted_position() const;
};