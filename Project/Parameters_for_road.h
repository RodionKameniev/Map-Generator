#pragma once
#include <iostream>
#include <string_view>
#include "Parameters_base.h"
#include "Type_of_road.h"

class Parameters_for_road : public Parameters_base {
protected:
    int cost_to_build = 0;
    Type_of_road type_of_road;
public:
    Parameters_for_road(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const int cost_to_build,
        const Type_of_road type_of_road,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    );

    // Set functions

    void set_cost_to_build(const int value);

    void set_type_of_road(const Type_of_road type_of_road);

    // Get functions

    const int get_cost_to_build() const;

    const Type_of_road get_type_of_road() const;
};