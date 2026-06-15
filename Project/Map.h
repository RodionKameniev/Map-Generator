#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX


#include <windows.h>
#include <utility>

#include <stdexcept>

#include <memory>
#include <vector>

#include "Size_dimensional.h"
#include "Cell_on_map.h"
#include "Clutter_cluster_spawn.h"
#include "Position.h"

class City;

class Map {
protected:
    Size_dimensional size_of_mini_map;

    Size_dimensional size_of_map;

    std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
    > cells_on_mini_map;

    std::vector<std::unique_ptr<City>> cities;

    std::vector<Clutter_cluster_spawn>
        clutters_probability_to_spawn;

public:
    std::vector<Position> place_for_clutters;
    std::vector<std::vector<Clutter_cluster_spawn>> var_of_clutter_clusters;
    // Constructor
    Map();
    Map(
        const Size_dimensional& size_of_mini_map,
        const Size_dimensional& size_of_map,
        std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
        > cells_on_mini_map,
        const std::vector<std::unique_ptr<City>>cities,
        const std::vector<
        Clutter_cluster_spawn
        >& clutters_probability_to_spawn
    );

    // Set functions
    void set(
        const Size_dimensional& size_of_mini_map,
        const Size_dimensional& size_of_map,
        std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
        > cells_on_mini_map,
        std::vector<std::unique_ptr<City>>cities,
        const std::vector<
        Clutter_cluster_spawn
        >& clutters_probability_to_spawn
    );

    void set_size_of_mini_map(
        const Size_dimensional& size_of_mini_map
    );

    void set_size_of_map(
        const Size_dimensional& size_of_map
    );

    void set_cells_on_mini_map(
        std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
        > cells_on_mini_map
    );

    void set_cities(
        std::vector<std::unique_ptr<City>>cities
    );

    void set_clutters_probability_to_spawn(
        const std::vector<
        Clutter_cluster_spawn
        >& clutters_probability_to_spawn
    );

    // Get functions
    const Size_dimensional&
        get_size_of_mini_map() const;

    const Size_dimensional&
        get_size_of_map() const;

    const std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
    >&
        get_cells_on_mini_map() const;
    std::vector<
        std::vector<
        std::unique_ptr<Cell_on_map>
        >
    >&
        get_cells_on_mini_map();

    const std::vector<std::unique_ptr<City>>&
        get_cities() const;

    const std::vector<
        Clutter_cluster_spawn
    >&
        get_clutters_probability_to_spawn() const;

    void create_base_map(int* values, int height, int width);

    static LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam
    );


    // Algorithms

    void render_map();

    void add_city(std::unique_ptr<City> city_to_add);

    bool possible_to_place_clutter(Position pos);

    void create_clutters(int amount);

    void create_roads();
};