#include <iostream>
#include "Size_dimensional.h"
#include <string_view>

using namespace std;

class Parameters_for_building {
protected:
    string name = "";
    int cost = 0;
    Size_dimensional for_mini_map;
    Size_dimensional for_map;
    int image_for_mini_map_id = 0;
    int image_for_map_id = 0;

public:
    Parameters_for_building(
        string_view name,
        const int cost,
        const Size_dimensional& for_mini_map,
        const Size_dimensional& for_map,
        const int image_for_mini_map_id,
        const int image_for_map_id
    )
        : name(name),
        cost(cost),
        for_mini_map(for_mini_map),
        for_map(for_map),
        image_for_mini_map_id(image_for_mini_map_id),
        image_for_map_id(image_for_map_id)
    {
        cout << "Parameters_for_building is called" << endl;
    }

    // Set functions
    void set(
        string_view name,
        const int cost,
        const Size_dimensional& for_mini_map,
        const Size_dimensional& for_map,
        const int image_for_mini_map_id,
        const int image_for_map_id
    ) {
        this->name = name;
        this->cost = cost;
        this->for_mini_map = for_mini_map;
        this->for_map = for_map;
        this->image_for_mini_map_id = image_for_mini_map_id;
        this->image_for_map_id = image_for_map_id;
    }

    void set_name(string_view name) {
        this->name = name;
    }

    void set_cost(const int cost) {
        this->cost = cost;
    }

    void set_for_mini_map(const Size_dimensional& for_mini_map) {
        this->for_mini_map = for_mini_map;
    }

    void set_for_map(const Size_dimensional& for_map) {
        this->for_map = for_map;
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

    const int get_cost() const {
        return this->cost;
    }

    const Size_dimensional& get_for_mini_map() const {
        return this->for_mini_map;
    }

    const Size_dimensional& get_for_map() const {
        return this->for_map;
    }

    const int get_image_for_mini_map_id() const {
        return this->image_for_mini_map_id;
    }

    const int get_image_for_map_id() const {
        return this->image_for_map_id;
    }
};