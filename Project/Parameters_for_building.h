#pragma once
#include <iostream>
#include "Parameters_base.h"
#include <string_view>

using namespace std;

class Parameters_for_building : public Parameters_base {
protected:
    int cost = 0;

public:
    Parameters_for_building(
        string_view name,
        const int cost,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        :
        Parameters_base(
            name,
            false,
            -1,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost(cost)
    {
        cout << "Parameters_for_building is called" << endl;
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