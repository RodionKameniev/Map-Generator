#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include "Parameters_base.h"
#include "Type_of_clutter.h"
#include "Colour.h"

class Parameters_for_clutter : public Parameters_base {
protected:
    Type_of_clutter type_of_clutter;

public:
    Parameters_for_clutter(
        std::string_view name,
        const Type_of_clutter type_of_clutter,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    );

    // Set functions
    void set_type_of_clutter(const Type_of_clutter type);

    // Get functions
    const Type_of_clutter get_type_of_clutter() const;
};