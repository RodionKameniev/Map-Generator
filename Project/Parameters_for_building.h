#pragma once
#include <iostream>
#include "Parameters_base.h"
#include <string_view>
#include <string>

class Parameters_for_building : public Parameters_base {
protected:
    int cost = 0;

public:
    Parameters_for_building(
        std::string_view name,
        const int cost,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        :
        Parameters_base(
            name,
            false,
            false,
            -1,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost(cost)
    {
        std::cout << "Parameters_for_building is called" << std::endl;
    }

    // Set functions

    void set_cost(
        const int cost
    ) {
        this->cost = cost;
    }

    // Get functions
    const int get_cost() const {
        return this->cost;
    }
};