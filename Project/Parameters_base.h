#include <iostream>
#include <string_view>
using namespace std;

class Parameters_base {
protected:
    string name = "";
    bool is_restrincted_ro_cross = false;
    int cost_to_cross = 0;
    int image_for_mini_map_id = 0;
    int image_for_map_id = 0;

public:
    Parameters_base(
        string_view name,
        const bool is_restrincted_ro_cross,
        const int cost_to_cross,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        : name(name),
        is_restrincted_ro_cross(is_restrincted_ro_cross),
        cost_to_cross(cost_to_cross),
        image_for_mini_map_id(image_for_mini_map_id),
        image_for_map_id(image_for_map_id) {

        cout << "Parameters_for_road is called" << endl;
    }

    // Set functions
    void set(
        string_view name,
        const bool is_restrincted_ro_cross,
        const int cost_to_cross,
        const int image_for_mini_map_id,
        const int image_for_map_id
    ) {
        this->name = name;
        this->is_restrincted_ro_cross = is_restrincted_ro_cross;
        this->cost_to_cross = cost_to_cross;
        this->image_for_mini_map_id = image_for_mini_map_id;
        this->image_for_map_id = image_for_map_id;
    }

    void set_name(string_view name) {
        this->name = name;
    }


    void set_is_restrincted_ro_cross(const bool is_restrincted_ro_cross) {
        this->is_restrincted_ro_cross = is_restrincted_ro_cross;
    }

    void set_cost_to_cross(const int cost_to_cross) {
        this->cost_to_cross = cost_to_cross;
    }


    void set_image_for_mini_map_id(const int image_for_mini_map_id) {
        this->image_for_mini_map_id = image_for_mini_map_id;
    }

    void set_image_for_map_id(const int image_for_map_id) {
        this->image_for_map_id = image_for_map_id;
    }

    // Get functions
    const string& get_name() const {
        return this->name;
    }

    const bool get_is_restrincted_ro_cross() const {
        return this->is_restrincted_ro_cross;
    }

    const int get_cost_to_cross() const {
        return this->cost_to_cross;
    }

    const int get_image_for_mini_map_id() const {
        return this->image_for_mini_map_id;
    }

    const int get_image_for_map_id() const {
        return this->image_for_map_id;
    }
};