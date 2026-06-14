#pragma once
#include <iostream>
#include "Clutter_cluster.h"
#include "Position.h"

class Map;

class Clutter_cluster_spawn {
protected:
    const Clutter_cluster* clutter;

    float probability_to_spawn;

public:
    Clutter_cluster_spawn(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    );

    // Set functions
    void set(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    );

    void set_clutter(
        const Clutter_cluster* clutter
    );

    void set_probability_to_spawn(
        const float probability_to_spawn
    );

    // Get functions
    const Clutter_cluster*
        get_clutter() const;

    const float get_probability_to_spawn() const;
    
    bool try_to_build(Map& map, Position start_of_clutter);

    void build_clutter(Map& map, Position start_of_clutter);
};