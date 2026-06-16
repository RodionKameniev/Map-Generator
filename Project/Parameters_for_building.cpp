#include "Parameters_for_building.h"
#include <iostream>
#include "Parameters_base.h"
#include <string>
#include <string_view>
#include <string>

Parameters_for_building::Parameters_for_building(
        std::string_view name,
        const int cost,
        const Colour image_for_mini_map_id,
        const Colour image_for_map_id
    )
        :
        Parameters_base(
            name,
            true,
            true,
            true,
            -1,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost(cost)
    {
        //std::cout << "Parameters_for_building is called" << std::endl;
    }

    // Set functions

    void Parameters_for_building::set_cost(
        const int cost
    ) {
        this->cost = cost;
    }

    // Get functions
    const int Parameters_for_building::get_cost() const {
        return this->cost;
    }