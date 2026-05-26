#include "Building_cluster_spawn.h"

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#include "Map.h"
#include "Road_on_map.h"
#include "Clutter_on_map.h"
#include "Building_on_map.h"
#include "Street_on_map.h"

using namespace std;


    Building_cluster_spawn::Building_cluster_spawn(
        const Building_cluster* building,
        const float probability_to_spawn
    )
        :
        building(building),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Building_cluster_spawn is called" << endl;
    }

    // Set functions
    void Building_cluster_spawn::set_all(
        const Building_cluster* building,
        const float probability_to_spawn
    ) {
        this->building =
            building;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void Building_cluster_spawn::set_building(
        const Building_cluster* building
    ) {
        this->building =
            building;
    }

    void Building_cluster_spawn::set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Building_cluster*
        Building_cluster_spawn::get_building() const {
        return this->building;
    }

    const float Building_cluster_spawn::get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }