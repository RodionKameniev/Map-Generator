#pragma once
#include <iostream>
#include "Size_dimensional.h"
#include <string>
#include <string_view>
#include <string>

class Parameters_for_city {
protected:
    std::string name = "";
    Size_dimensional for_mini_map;
    Size_dimensional for_map;

public:
    Parameters_for_city(
        std::string_view city_name,
        const Size_dimensional& city_for_mini_map,
        const Size_dimensional& city_for_map
    );
    Parameters_for_city(
        std::string_view city_name
    );

    // Set functions
    void set(
        std::string_view city_name,
        const Size_dimensional& city_for_mini_map,
        const Size_dimensional& city_for_map
    );

    void set_name(
        std::string_view city_name
    );

    void set_for_mini_map(
        const Size_dimensional& city_for_mini_map
    );

    void set_for_map(
        const Size_dimensional& city_for_map
    );

    // Get functions
    const std::string& get_name() const;

    const Size_dimensional&
        get_for_mini_map() const;

    const Size_dimensional&
        get_for_map() const;
};