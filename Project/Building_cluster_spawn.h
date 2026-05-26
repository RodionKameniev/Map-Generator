#pragma once
#include <iostream>
#include "Building_cluster.h"

using namespace std;

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
};