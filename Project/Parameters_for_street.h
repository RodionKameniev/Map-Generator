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
        string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const int cost_to_build,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        : Parameters_base(
            name,
            is_restricted_to_cross,
            is_restricted_to_build,
            cost_to_cross,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost_to_build(cost_to_build)
    {
        cout << "Parameters_for_street is called" << endl;
    }

    // Set functions
    void set_cost_to_build(int value) {
        this->cost_to_build = value;
    }

    // Get functions

    const int get_cost_to_build() const {
        return this->cost_to_build;
    }
};