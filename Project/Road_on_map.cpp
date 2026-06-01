#include "Road_on_map.h"
#include <iostream>
#include <vector>
#include "Parameters_for_road.h"
#include "Cell_on_map.h"
#include "Direction.h"


Road_on_map::Road_on_map(
        const Position& position,
        const Parameters_for_road* road_to_be_placed,
        const std::vector<Direction>& direction_of_connections
    )
        :
        Cell_on_map(
            position,
            Type_of_object::Road
        ),
        road_to_be_placed(road_to_be_placed),
        direction_of_connections(direction_of_connections)
    {
        std::cout << "Road_on_map is called" << std::endl;
    }

    // Set functions
    void Road_on_map::set(
        Parameters_for_road* road_to_be_placed,
        const std::vector<Direction>& direction_of_connections
    ) {
        this->road_to_be_placed =
            road_to_be_placed;

        this->direction_of_connections =
            direction_of_connections;

    }

    void Road_on_map::set_road_to_be_placed(
        Parameters_for_road* road_to_be_placed
    ) {
        this->road_to_be_placed =
            road_to_be_placed;
    }

    void Road_on_map::set_direction_of_connections(
        const std::vector<Direction>& direction_of_connections
    ) {
        this->direction_of_connections =
            direction_of_connections;
    }

    // Get functions
    const Parameters_for_road*
        Road_on_map::get_road_to_be_placed() const {
        return this->road_to_be_placed;
    }

    const std::vector<Direction>&
        Road_on_map::get_direction_of_connections() const {
        return this->direction_of_connections;
    }