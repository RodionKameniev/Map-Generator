#include "End_of_street.h"

#include <iostream>

#include "City.h"
#include "Direction.h"
#include "Position.h"


End_of_street::End_of_street(
        const Position& position,
        const City* from_which_city,
        const Direction direction
    )
        :
        position(position),
        from_which_city(from_which_city),
        direction(direction)
    {
        //std::cout << "Clutter_spawn is called"<< std::endl;
    }

    // Set functions
    void End_of_street::set(
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

    void End_of_street::set_position(
        const Position& position
    ) {
        this->position =
            position;
    }

    void End_of_street::set_from_which_city(
        const City* from_which_city
    ) {
        this->from_which_city =
            from_which_city;
    }

    void End_of_street::set_direction(
        const Direction direction
    ) {
        this->direction =
            direction;
    }

    // Get functions
    const Position&
        End_of_street::get_position() const {
        return this->position;
    }

    const City* End_of_street::get_from_which_city() const {
        return this->from_which_city;
    }

    const Direction End_of_street::get_direction() const {
        return this->direction;
    }