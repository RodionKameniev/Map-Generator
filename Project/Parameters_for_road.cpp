#include "Parameters_for_road.h"

#include <iostream>
#include <string_view>
#include "Parameters_base.h"
#include "Type_of_road.h"


Parameters_for_road::Parameters_for_road(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const int cost_to_build,
        const Type_of_road type_of_road,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    )
        : Parameters_base(
            name,
            is_restricted_to_cross,
            is_restricted_to_build,
            cost_to_cross,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost_to_build(cost_to_build),
        type_of_road(type_of_road)
    {
        std::cout << "Parameters_for_road is called" << std::endl;
    }

    // Set functions

    void Parameters_for_road::set_cost_to_build(const int value) {
        this->cost_to_build = value;
    }

    void Parameters_for_road::set_type_of_road(const Type_of_road type_of_road) {
        this->type_of_road = type_of_road;
    }

    // Get functions

    const int Parameters_for_road::get_cost_to_build() const {
        return this->cost_to_build;
    }

    const Type_of_road Parameters_for_road::get_type_of_road() const {
        return this->type_of_road;
    }