#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include "Colour.h"

class Parameters_base {
protected:
    std::string name;
    bool is_restricted_to_cross = false;
    bool is_restricted_to_build = false;
    int cost_to_cross = 0;
    Colour image_for_mini_map_id;
    Colour image_for_map_id;

public:
    Parameters_base(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const Colour& image_for_mini_map_id,
        const Colour& image_for_map_id
    );

    // Set functions
    void set(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const Colour& image_for_mini_map_id,
        const Colour& image_for_map_id
    );

    void set_name(std::string_view name);


    void set_is_restricted_to_cross(const bool is_restricted_to_cross);

    void set_is_restricted_to_build(const bool is_restricted_to_build);

    void set_cost_to_cross(const int cost_to_cross);


    void set_image_for_mini_map_id(const Colour& image_for_mini_map_id);

    void set_image_for_map_id(const Colour& image_for_map_id);

    // Get functions
    const std::string& get_name() const;

    const bool get_is_restricted_to_cross() const;

    const bool get_is_restricted_to_build() const;

    const int get_cost_to_cross() const;

    const Colour& get_image_for_mini_map_id() const;

    const Colour& get_image_for_map_id() const;
};