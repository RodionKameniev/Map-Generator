#include "Clutter_cluster_spawn.h"

#include <iostream>
#include "Clutter_cluster.h"

#include "Map.h"
#include "Road_on_map.h"
#include "Clutter_on_map.h"
#include "Building_on_map.h"
#include "Street_on_map.h"

Clutter_cluster_spawn::Clutter_cluster_spawn(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    )
        :
        clutter(clutter),
        probability_to_spawn(probability_to_spawn)
    {
        std::cout << "Clutter_cluster_spawn is called" << std::endl;
    }

    // Set functions
    void Clutter_cluster_spawn::set(
        const Clutter_cluster* clutter,
        const float probability_to_spawn
    ) {
        this->clutter =
            clutter;

        this->probability_to_spawn =
            probability_to_spawn;
    }

    void Clutter_cluster_spawn::set_clutter(
        const Clutter_cluster* clutter
    ) {
        this->clutter =
            clutter;
    }

    void Clutter_cluster_spawn::set_probability_to_spawn(
        const float probability_to_spawn
    ) {
        this->probability_to_spawn =
            probability_to_spawn;
    }

    // Get functions
    const Clutter_cluster*
        Clutter_cluster_spawn::get_clutter() const {
        return this->clutter;
    }

    const float Clutter_cluster_spawn::get_probability_to_spawn() const {
        return this->probability_to_spawn;
    }

    bool Clutter_cluster_spawn::try_to_build(Map& map, Position start_of_clutter) {
        for (int i = 0; i < this->get_clutter()->get_clutter_components().size(); i++) {

            Position shifted_pos = this->get_clutter()->get_clutter_components()[i].get_shifted_position();

            shifted_pos.set_on_x(shifted_pos.get_on_x() + start_of_clutter.get_on_x());
            shifted_pos.set_on_y(shifted_pos.get_on_y() + start_of_clutter.get_on_y());
            int shifted_x = shifted_pos.get_on_x();
            int shifted_y = shifted_pos.get_on_y();

            Cell_on_map* cell = map.get_cells_on_mini_map()[shifted_x][shifted_y].get();

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

    void Clutter_cluster_spawn::build_clutter(Map& map, Position start_of_clutter) {
        //Changing cells to clutters
        for (int i = 0; i < this->get_clutter()->get_clutter_components().size(); i++) {

            Position shifted_pos = this->get_clutter()->get_clutter_components()[i].get_shifted_position();

            shifted_pos.set_on_x(shifted_pos.get_on_x() + start_of_clutter.get_on_x());
            shifted_pos.set_on_y(shifted_pos.get_on_y() + start_of_clutter.get_on_y());
            int shifted_x = shifted_pos.get_on_x();
            int shifted_y = shifted_pos.get_on_y();

            map.get_cells_on_mini_map()[shifted_x][shifted_y] = make_unique<Clutter_on_map>(shifted_pos, this->get_clutter()->get_clutter_components()[i].get_clutter_part(), vector<Direction>{}, this->get_probability_to_spawn());
        }
    }