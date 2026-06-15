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


Building_cluster_spawn::Building_cluster_spawn(
    const Building_cluster* building,
    const float probability_to_spawn
)
    :
    building(building),
    probability_to_spawn(probability_to_spawn)
{
    std::cout << "Building_cluster_spawn is called" << std::endl;
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

//Algorithms

bool Building_cluster_spawn::try_to_build(Map& map, Position place, int center_pos_x, int center_pos_y, int center_size_x, int center_size_y) {
    for (int i = 0; i < this->get_building()->get_building_components().size(); i++) {

        if ((place.get_on_x() > center_pos_x + center_size_x)
            || (place.get_on_x() < center_pos_x - center_size_x)
            || (place.get_on_y() > center_pos_y + center_size_y)
            || (place.get_on_y() < center_pos_y - center_size_y)) {
            return false;
        }

        Position shifted_pos = this->get_building()->get_building_components()[i].get_shifted_position();

        shifted_pos.set_on_x(shifted_pos.get_on_x() + place.get_on_x());
        shifted_pos.set_on_y(shifted_pos.get_on_y() + place.get_on_y());
        int shifted_x = shifted_pos.get_on_x();
        int shifted_y = shifted_pos.get_on_y();

        Cell_on_map* cell = map.get_cells_on_mini_map()[shifted_y][shifted_x].get();

        // Road
        if (dynamic_cast<Road_on_map*>(cell)) {
            Road_on_map* road = dynamic_cast<Road_on_map*>(cell);
            const Parameters_for_road* params = road->get_road_to_be_placed();

            if (params->get_is_restricted_to_build()) {
                return false;
            }
        }

        // Clutter
        if (dynamic_cast<Clutter_on_map*>(cell)) {
            Clutter_on_map* clutter = dynamic_cast<Clutter_on_map*>(cell);

            const Parameters_for_clutter* params = clutter->get_clutter_to_be_placed();

            if (params->get_is_restricted_to_build()) {
                return false;
            }
        }

        // Building
        if (dynamic_cast<Building_on_map*>(cell)) {
            Building_on_map* building = dynamic_cast<Building_on_map*>(cell);
            const Parameters_for_building* params = building->get_building_to_be_placed();

            if (params->get_is_restricted_to_build()) {
                return false;
            }
        }

        // Street
        if (dynamic_cast<Street_on_map*>(cell)) {
            Street_on_map* street = dynamic_cast<Street_on_map*>(cell);
            const Parameters_for_street* params = street->get_street_to_be_placed();

            if (params->get_is_restricted_to_build()) {
                return false;
            }
        }
    }

    return true;
}

void Building_cluster_spawn::build_building(Map& map, Position place) {
    //Changing cells to buildings
    for (int i = 0; i < this->get_building()->get_building_components().size(); i++) {

        Position shifted_pos = this->get_building()->get_building_components()[i].get_shifted_position();

        shifted_pos.set_on_x(shifted_pos.get_on_x() + place.get_on_x());
        shifted_pos.set_on_y(shifted_pos.get_on_y() + place.get_on_y());
        int shifted_x = shifted_pos.get_on_x();
        int shifted_y = shifted_pos.get_on_y();

        map.get_cells_on_mini_map()[shifted_y][shifted_x] = make_unique<Building_on_map>(shifted_pos, this->get_building()->get_building_components()[i].get_building_part(), Direction::None, this->get_probability_to_spawn());
    }
}