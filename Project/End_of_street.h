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
    )
        :
        position(position),
        from_which_city(from_which_city),
        direction(direction)
    {
        std::cout << "Clutter_spawn is called"
            << std::endl;
    }

    // Set functions
    void set(
        const Position& position,
        const City* from_which_city,
        const Direction direction
    ) {
        this->position =
            position;

        this->from_which_city =
            from_which_city;

        this->direction =
            direction;
    }

    void set_position(
        const Position& position
    ) {
        this->position =
            position;
    }

    void set_from_which_city(
        const City* from_which_city
    ) {
        this->from_which_city =
            from_which_city;
    }

    void set_direction(
        const Direction direction
    ) {
        this->direction =
            direction;
    }

    // Get functions
    const Position&
        get_position() const {
        return this->position;
    }

    const City* get_from_which_city() const {
        return this->from_which_city;
    }

    const Direction get_direction() const {
        return this->direction;
    }
};