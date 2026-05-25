#include "Map.h"

#include <iostream>
#include <utility>

#include "City.h"

using namespace std;

// Constructor
Map::Map(
    const Size_dimensional& size_of_mini_map,
    const Size_dimensional& size_of_map,

    vector<
    vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map,

    const vector<City*>& cities,

    const vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
)
    :
    size_of_mini_map(size_of_mini_map),

    size_of_map(size_of_map),

    cells_on_mini_map(
        move(cells_on_mini_map)
    ),

    cities(cities),

    clutters_probability_to_spawn(
        clutters_probability_to_spawn
    )
{
    cout << "Map is called"
        << endl;
}

// Set functions
void Map::set(
    const Size_dimensional& size_of_mini_map,

    const Size_dimensional& size_of_map,

    vector<
    vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map,

    const vector<City*>& cities,

    const vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
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

void Map::set_size_of_mini_map(
    const Size_dimensional&
    size_of_mini_map
) {
    this->size_of_mini_map =
        size_of_mini_map;
}

void Map::set_size_of_map(
    const Size_dimensional&
    size_of_map
) {
    this->size_of_map =
        size_of_map;
}

void Map::set_cells_on_mini_map(
    vector<
    vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map
) {
    this->cells_on_mini_map =
        move(cells_on_mini_map);
}

void Map::set_cities(
    const vector<City*>& cities
) {
    this->cities = cities;
}

void Map::
set_clutters_probability_to_spawn(
    const vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
) {
    this->clutters_probability_to_spawn =
        clutters_probability_to_spawn;
}

// Get functions
const Size_dimensional&
Map::get_size_of_mini_map() const {
    return this->size_of_mini_map;
}

const Size_dimensional&
Map::get_size_of_map() const {
    return this->size_of_map;
}

const vector<
    vector<
    unique_ptr<Cell_on_map>
    >
>&
Map::get_cells_on_mini_map() const {
    return this->cells_on_mini_map;
}

const vector<City*>&
Map::get_cities() const {
    return this->cities;
}

const vector<
    Clutter_cluster_spawn
>&
Map::
get_clutters_probability_to_spawn() const {
    return this->clutters_probability_to_spawn;
}

    // Functions