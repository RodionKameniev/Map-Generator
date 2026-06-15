#pragma once
#include <iostream>

#include "Building_cluster.h"
#include "Position.h"
#include "Map.h"

class Map;

class Building_cluster_spawn {
protected:
    const Building_cluster* building;

    float probability_to_spawn;

public:
    Building_cluster_spawn(
        const Building_cluster* building,
        const float probability_to_spawn
    );

    // Set functions
    void set_all(
        const Building_cluster* building,
        const float probability_to_spawn
    );

    void set_building(
        const Building_cluster* building
    );

    void set_probability_to_spawn(
        const float probability_to_spawn
    );

    // Get functions
    const Building_cluster*
        get_building() const;

    const float get_probability_to_spawn() const;


    //Algoritms
    bool try_to_build(Map& map, Position place, int center_pos_x, int center_pos_y, int center_size_x, int center_size_y);
    
    void build_building(Map& map, Position place);
};