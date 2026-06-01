#include "Clutter_on_map.h"

#include <iostream>
#include <vector>
#include "Parameters_for_clutter.h"
#include "Cell_on_map.h"
#include "Direction.h"

Clutter_on_map::Clutter_on_map(
        const Position& position,
        const Parameters_for_clutter* clutter_to_be_placed,
        const std::vector<Direction>& direction_of_connections,
        const float base_probability_to_spawn
    )
        :
        Cell_on_map(
            position,
            Type_of_object::Clutter
        ),
        clutter_to_be_placed(clutter_to_be_placed),
        direction_of_connections(direction_of_connections)
    {
        //std::cout << "Clutter_on_map is called" << std::endl;
    }

    // Set functions
    void Clutter_on_map::set(
        const Parameters_for_clutter* clutter_to_be_placed,
        const std::vector<Direction>& direction_of_connections,
        const float base_probability_to_spawn
    ) {
        this->clutter_to_be_placed =
            clutter_to_be_placed;

        this->direction_of_connections =
            direction_of_connections;

    }

    void Clutter_on_map::set_clutter_to_be_placed(
        const Parameters_for_clutter* clutter_to_be_placed
    ) {
        this->clutter_to_be_placed =
            clutter_to_be_placed;
    }

    void Clutter_on_map::set_direction_of_connections(
        const std::vector<Direction>& direction_of_connections
    ) {
        this->direction_of_connections =
            direction_of_connections;
    }


    // Get functions
    const Parameters_for_clutter*
        Clutter_on_map::get_clutter_to_be_placed() const {
        return this->clutter_to_be_placed;
    }

    const std::vector<Direction>&
        Clutter_on_map::get_direction_of_connections() const {
        return this->direction_of_connections;
    }
