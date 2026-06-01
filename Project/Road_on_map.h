#pragma once
#include <iostream>
#include <vector>
#include "Parameters_for_road.h"
#include "Cell_on_map.h"
#include "Direction.h"

class Road_on_map : public Cell_on_map {
protected:
    const Parameters_for_road* road_to_be_placed;
    std::vector<Direction> direction_of_connections;

public:
    Road_on_map(
        const Position& position,
        const Parameters_for_road* road_to_be_placed,
        const std::vector<Direction>& direction_of_connections
    );

    // Set functions
    void set(
        Parameters_for_road* road_to_be_placed,
        const std::vector<Direction>& direction_of_connections
    );

    void set_road_to_be_placed(
        Parameters_for_road* road_to_be_placed
    );

    void set_direction_of_connections(
        const std::vector<Direction>& direction_of_connections
    );

    // Get functions
    const Parameters_for_road*
        get_road_to_be_placed() const;

    const std::vector<Direction>&
        get_direction_of_connections() const;
};