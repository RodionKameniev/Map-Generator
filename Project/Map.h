#pragma once
#include <iostream>
#include <vector>

#include "Size_dimensional.h"
#include "Cell_on_map.h"
#include "City.h"
#include "Clutter_cluster_spawn.h"

using namespace std;

class Map {
protected:
    Size_dimensional size_of_mini_map;

    Size_dimensional size_of_map;

    vector<vector<unique_ptr<Cell_on_map>>> cells_on_mini_map;

    vector<City*> cities;

    vector<Clutter_cluster_spawn> clutters_probability_to_spawn;

public:
    Map(
        const Size_dimensional& size_of_mini_map,
        const Size_dimensional& size_of_map,
        const vector<vector<unique_ptr<Cell_on_map>>>& cells_on_mini_map,
        const vector<City*>& cities,
        const vector<Clutter_cluster_spawn>& clutters_probability_to_spawn
    )
        :
        size_of_mini_map(size_of_mini_map),
        size_of_map(size_of_map),
        cells_on_mini_map(cells_on_mini_map),
        cities(cities),
        clutters_probability_to_spawn(
            clutters_probability_to_spawn
        )
    {
        cout << "Map is called" << endl;
    }

    // Set functions
    void set(
        const Size_dimensional& size_of_mini_map,
        const Size_dimensional& size_of_map,
        const vector<vector<unique_ptr<Cell_on_map>>> cells_on_mini_map,
        const vector<City*>& cities,
        const vector<Clutter_cluster_spawn>& clutters_probability_to_spawn
    ) {
        this->size_of_mini_map =
            size_of_mini_map;

        this->size_of_map =
            size_of_map;

        this->cells_on_mini_map =
            move(cells_on_mini_map);

        this->cities =
            cities;

        this->clutters_probability_to_spawn =
            clutters_probability_to_spawn;
    }

    void set_size_of_mini_map(
        const Size_dimensional& size_of_mini_map
    ) {
        this->size_of_mini_map =
            size_of_mini_map;
    }

    void set_size_of_map(
        const Size_dimensional& size_of_map
    ) {
        this->size_of_map =
            size_of_map;
    }

    void set_cells_on_mini_map(
        const vector<vector<unique_ptr<Cell_on_map>>>&
        cells_on_mini_map
    ) {
        this->cells_on_mini_map =
            move(cells_on_mini_map);
    }

    void set_cities(
        const vector<City*>& cities
    ) {
        this->cities =
            cities;
    }

    void set_clutters_probability_to_spawn(
        const vector<Clutter_cluster_spawn>&
        clutters_probability_to_spawn
    ) {
        this->clutters_probability_to_spawn =
            clutters_probability_to_spawn;
    }

    // Get functions
    const Size_dimensional&
        get_size_of_mini_map() const {
        return this->size_of_mini_map;
    }

    const Size_dimensional&
        get_size_of_map() const {
        return this->size_of_map;
    }

    const vector<vector<unique_ptr<Cell_on_map>>>&
        get_cells_on_mini_map() const {
        return this->cells_on_mini_map;
    }

    const vector<City*>&
        get_cities() const {
        return this->cities;
    }

    const vector<Clutter_cluster_spawn>&
        get_clutters_probability_to_spawn() const {
        return this->clutters_probability_to_spawn;
    }
};