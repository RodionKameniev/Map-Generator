#pragma once
#include <iostream>
#include "Parameters_base.h"
#include <string>
#include <string_view>
#include <string>

class Parameters_for_building : public Parameters_base {
protected:
    int cost = 0;

public:
    Parameters_for_building(
        std::string_view name,
        const int cost,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    );

    // Set functions

    void set_cost(
        const int cost
    );
    // Get functions
    const int get_cost() const;
};