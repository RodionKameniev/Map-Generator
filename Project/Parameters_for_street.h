#pragma once
#include <iostream>
#include <string_view>
#include "Parameters_base.h"
using namespace std;

class Parameters_for_street : public Parameters_base {
protected:
    int cost_to_build = 0;

public:
    Parameters_for_street(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const int cost_to_build,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    );

    // Set functions
    void set_cost_to_build(int value);

    // Get functions

    const int get_cost_to_build() const;
};