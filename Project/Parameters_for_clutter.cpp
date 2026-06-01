#include "Parameters_for_clutter.h"
#include <iostream>
#include <string>
#include <string_view>
#include "Parameters_base.h"
#include "Type_of_clutter.h"
#include "Colour.h"


Parameters_for_clutter::Parameters_for_clutter(
        std::string_view name,
        const Type_of_clutter type_of_clutter,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
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
        type_of_clutter(type_of_clutter)
    {
        std::cout << "Parameters_for_clutter is called" << std::endl;
    }

    // Set functions
    void Parameters_for_clutter::set_type_of_clutter(const Type_of_clutter type) {
        this->type_of_clutter = type;
    }

    // Get functions
    const Type_of_clutter Parameters_for_clutter::get_type_of_clutter() const {
        return this->type_of_clutter;
    }