#pragma once

#include "Street_cluster.h"
#include "Position.h"

class Map;

class Street_cluster_spawn {
protected:
    const Street_cluster* street;

    float probability_to_spawn;

public:
    // Constructor
    Street_cluster_spawn(
        const Street_cluster* street,
        float probability_to_spawn
    );

    // Set functions
    void set(
        const Street_cluster* street,
        float probability_to_spawn
    );

    void set_street(
        const Street_cluster* street
    );

    void set_probability_to_spawn(
        float probability_to_spawn
    );

    // Get functions
    const Street_cluster* get_street() const;

    float get_probability_to_spawn() const;

    // Algorithms
    bool try_to_build(
        Map& map,
        Position start_of_street
    );
};