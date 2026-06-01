#pragma once
#include <iostream>

#include "City.h"
#include "Direction.h"
#include "Position.h"


class End_of_street {
protected:
    Position position;

    const City* from_which_city;

    Direction direction;

public:
    End_of_street(
        const Position& position,
        const City* from_which_city,
        const Direction direction
    );

    // Set functions
    void set(
        const Position& position,
        const City* from_which_city,
        const Direction direction
    );

    void set_position(
        const Position& position
    );

    void set_from_which_city(
        const City* from_which_city
    );

    void set_direction(
        const Direction direction
    );

    // Get functions
    const Position&
        get_position() const;

    const City* get_from_which_city() const;

    const Direction get_direction() const;
};