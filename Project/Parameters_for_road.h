#include <iostream>
#include <string_view>
#include "Parameters_base.h"
#include "Type_of_road.h"

using namespace std;

class Parameters_for_road : public Parameters_base {
protected:
    int cost_to_build = 0;
    Type_of_road type_of_road;
public:
    Parameters_for_road(
        string_view name,
        const bool is_restricted_to_cross,
        const int cost_to_cross,
        const int cost_to_build,
        const Type_of_road type_of_road,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        : Parameters_base (
            name,
            is_restricted_to_cross,
            cost_to_cross,
            image_for_mini_map_id,
            image_for_map_id
        ),
        cost_to_build(cost_to_build),
        type_of_road(type_of_road)
    {
        cout << "Parameters_for_road is called\n";
    }

    // Set functions

    void set_cost_to_build(const int value) {
        this->cost_to_build = value;
    }

    void set_type_of_road(const Type_of_road type_of_road) {
        this->type_of_road = type_of_road;
    }

    // Get functions

    const int get_cost_to_build() const {
        return this->cost_to_build;
    }

    const Type_of_road get_type_of_road() const {
        return this->type_of_road;
    }
};