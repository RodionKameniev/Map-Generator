#pragma once

#include <vector>

#include "Building_cluster.h"
#include "Building_cluster_spawn.h"
#include "Street_cluster_spawn.h"
#include "Parameters_for_city.h"
#include "Position.h"

class Map;

class City {
protected:
    std::vector<Building_cluster>
        buildings;

    std::vector<
        Building_cluster_spawn
    > buildings_probability_to_spawn;

    std::vector<
        Street_cluster_spawn
    > streets_probability_to_spawn;

    Parameters_for_city parameters;

    int cost;

    Position center_of_city;

public:
    // Constructor
    City(
        const std::vector<
        Building_cluster
        >& buildings,

        const std::vector<
        Building_cluster_spawn
        >& buildings_probability_to_spawn,

        const std::vector<
        Street_cluster_spawn
        >& streets_probability_to_spawn,

        const Parameters_for_city&
        parameters,

        int cost,

        const Position&
        center_of_city
    );

    // Set functions
    void set(
        const std::vector<
        Building_cluster
        >& buildings,

        const std::vector<
        Building_cluster_spawn
        >& buildings_probability_to_spawn,

        const std::vector<
        Street_cluster_spawn
        >& streets_probability_to_spawn,

        const Parameters_for_city&
        parameters,

        int cost,

        const Position&
        center_of_city
    );

    void set_buildings(
        const std::vector<
        Building_cluster
        >& buildings
    );

    void set_buildings_probability_to_spawn(
        const std::vector<
        Building_cluster_spawn
        >& buildings_probability_to_spawn
    );

    void set_streets_probability_to_spawn(
        const std::vector<
        Street_cluster_spawn
        >& streets_probability_to_spawn
    );

    void set_parameters(
        const Parameters_for_city&
        parameters
    );

    void set_cost(
        int cost
    );

    void set_center_of_city(
        const Position&
        center_of_city
    );

    // Get functions
    const std::vector<
        Building_cluster
    >& get_buildings() const;

    const std::vector<
        Building_cluster_spawn
    >&
        get_buildings_probability_to_spawn() const;

    const std::vector<
        Street_cluster_spawn
    >&
        get_streets_probability_to_spawn() const;

    const Parameters_for_city&
        get_parameters() const;

    int get_cost() const;

    const Position&
        get_center_of_city() const;

    // Algorithms
    void create_streets(
        Map& map
    );
};