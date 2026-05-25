#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include "Building_cluster.h"
#include "Building_cluster_spawn.h"
#include "Street_cluster_spawn.h"
#include "Parameters_for_city.h"
#include "Position.h"


using namespace std;

//queue<Position> start_of_streets;

class City {
protected:
    vector<Building_cluster> buildings;

    vector<Building_cluster_spawn>
        buildings_probability_to_spawn;

    vector<Street_cluster_spawn>
        streets_probability_to_spawn;

    Parameters_for_city parameters;

    int cost;

    Position center_of_city;

public:
    City(
        const vector<Building_cluster>& buildings,
        const vector<Building_cluster_spawn>& buildings_probability_to_spawn,
        const vector<Street_cluster_spawn>& streets_probability_to_spawn,
        const Parameters_for_city& parameters,
        const int cost,
        const Position& center_of_city
    )
        :
        buildings(buildings),
        buildings_probability_to_spawn(
            buildings_probability_to_spawn
        ),
        streets_probability_to_spawn(
            streets_probability_to_spawn
        ),
        parameters(parameters),
        cost(cost),
        center_of_city(center_of_city)
    {
        cout << "Clutter_spawn is called" << endl;
    }

    // Set functions
    void set(
        const vector<Building_cluster>& buildings,
        const vector<Building_cluster_spawn>& buildings_probability_to_spawn,
        const vector<Street_cluster_spawn>& streets_probability_to_spawn,
        const Parameters_for_city& parameters,
        const int cost,
        const Position& center_of_city
    ) {
        this->buildings =
            buildings;

        this->buildings_probability_to_spawn =
            buildings_probability_to_spawn;

        this->streets_probability_to_spawn =
            streets_probability_to_spawn;

        this->parameters =
            parameters;

        this->cost =
            cost;

        this->center_of_city =
            center_of_city;
    }

    void set_buildings(
        const vector<Building_cluster>& buildings
    ) {
        this->buildings =
            buildings;
    }

    void set_buildings_probability_to_spawn(
        const vector<Building_cluster_spawn>&
        buildings_probability_to_spawn
    ) {
        this->buildings_probability_to_spawn =
            buildings_probability_to_spawn;
    }

    void set_streets_probability_to_spawn(
        const vector<Street_cluster_spawn>&
        streets_probability_to_spawn
    ) {
        this->streets_probability_to_spawn =
            streets_probability_to_spawn;
    }

    void set_parameters(
        const Parameters_for_city& parameters
    ) {
        this->parameters =
            parameters;
    }

    void set_cost(
        const int cost
    ) {
        this->cost =
            cost;
    }

    void set_center_of_city(
        const Position& center_of_city
    ) {
        this->center_of_city =
            center_of_city;
    }

    // Get functions
    const vector<Building_cluster>&
        get_buildings() const {
        return this->buildings;
    }

    const vector<Building_cluster_spawn>&
        get_buildings_probability_to_spawn() const {
        return this->buildings_probability_to_spawn;
    }

    const vector<Street_cluster_spawn>&
        get_streets_probability_to_spawn() const {
        return this->streets_probability_to_spawn;
    }

    const Parameters_for_city&
        get_parameters() const {
        return this->parameters;
    }

    const int get_cost() const {
        return this->cost;
    }

    const Position&
        get_center_of_city() const {
        return this->center_of_city;
    }
};