#pragma once
#include <iostream>
#include "Street_cluster.h"
#include "Map.h"
#include "Road_on_map.h"
#include "Clutter_on_map.h"
#include "Building_on_map.h"
#include "Street_on_map.h"

using namespace std;

class Street_cluster_spawn {
protected:
    const Street_cluster* street;

    float probability_to_spawn;

public:
    Street_cluster_spawn(
        const Street_cluster* street,
        const float probability_to_spawn
    )
        :
        street(street),
        probability_to_spawn(probability_to_spawn)
    {
        cout << "Street_spawn is called" << endl;
    }

    // Set functions
    void set(
        const Street_cluster* street,
        const float probability_to_spawn
    ) {
        this->street =
            street;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void set_street(
        const Street_cluster* street
    ) {
        this->street =
            street;
    }

    void set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Street_cluster*
        get_street() const {
        return this->street;
    }

    const float get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }

    //Algoritms

    bool try_to_build(Map& map, Position start_of_street) {
        vector<Position> all_street_points = vector<Position>();
        for (int i = 0; i < this->get_street()->get_street_components().size(); i++) {
            Position shifted_pos = this->get_street()->get_street_components()[i].get_shifted_position();
            shifted_pos.set_on_x(shifted_pos.get_on_x() + start_of_street.get_on_x());
            shifted_pos.set_on_y(shifted_pos.get_on_y() + start_of_street.get_on_y());
            int shifted_x = shifted_pos.get_on_x();
            int shifted_y = shifted_pos.get_on_y();
            Cell_on_map* cell = map.get_cells_on_mini_map()[shifted_x][shifted_y].get();
            if (dynamic_cast<Road_on_map*>(cell)) {
                Road_on_map* road = dynamic_cast<Road_on_map*>(cell);
                const Parameters_for_road* params = road->get_road_to_be_placed();
                if (!params->get_is_restricted_to_cross()) {
                    return false;
                }
            }
            if (dynamic_cast<Clutter_on_map*>(cell)) {
                Clutter_on_map* clutter = dynamic_cast<Clutter_on_map*>(cell);
                const Parameters_for_clutter* params = clutter->get_clutter_to_be_placed();
                if (!params->get_is_restricted_to_cross()){
                    return false;
                }
            }
            if (dynamic_cast<Building_on_map*>(cell)) {
                Building_on_map* building = dynamic_cast<Building_on_map*>(cell);
                const Parameters_for_building* params = building->get_building_to_be_placed();
                if (!params->get_is_restricted_to_cross()) {
                    return false;
                }
            }
            if (dynamic_cast<Street_on_map*>(cell)) {
                Street_on_map* street = dynamic_cast<Street_on_map*>(cell);
                const Parameters_for_street* params = street->get_street_to_be_placed();
                if (!params->get_is_restricted_to_cross()) {
                    return false;
                }
            }
        }
        return true;
    }
};