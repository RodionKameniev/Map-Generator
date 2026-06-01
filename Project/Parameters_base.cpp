#include "Parameters_base.h"
#include <iostream>
#include <string>
#include <string_view>

#include "Colour.h"


Parameters_base::Parameters_base(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const Colour& image_for_mini_map_id,
        const Colour& image_for_map_id
    )
        : name(name),
        is_restricted_to_cross(is_restricted_to_cross),
        is_restricted_to_build(is_restricted_to_build),
        cost_to_cross(cost_to_cross),
        image_for_mini_map_id(image_for_mini_map_id),
        image_for_map_id(image_for_map_id) {

        std::cout << "Parameters_base is called" << std::endl;
    }

    // Set functions
    void Parameters_base::set(
        std::string_view name,
        const bool is_restricted_to_cross,
        const bool is_restricted_to_build,
        const int cost_to_cross,
        const Colour& image_for_mini_map_id,
        const Colour& image_for_map_id
    ) {
        this->name = name;
        this->is_restricted_to_cross = is_restricted_to_cross;
        this->is_restricted_to_build = is_restricted_to_build;
        this->cost_to_cross = cost_to_cross;
        this->image_for_mini_map_id = image_for_mini_map_id;
        this->image_for_map_id = image_for_map_id;
    }

    void Parameters_base::set_name(std::string_view name) {
        this->name = name;
    }


    void Parameters_base::set_is_restricted_to_cross(const bool is_restricted_to_cross) {
        this->is_restricted_to_cross = is_restricted_to_cross;
    }

    void Parameters_base::set_is_restricted_to_build(const bool is_restricted_to_build) {
        this->is_restricted_to_build = is_restricted_to_build;
    }

    void Parameters_base::set_cost_to_cross(const int cost_to_cross) {
        this->cost_to_cross = cost_to_cross;
    }


    void Parameters_base::set_image_for_mini_map_id(const Colour& image_for_mini_map_id) {
        this->image_for_mini_map_id = image_for_mini_map_id;
    }

    void Parameters_base::set_image_for_map_id(const Colour& image_for_map_id) {
        this->image_for_map_id = image_for_map_id;
    }

    // Get functions
    const std::string& Parameters_base::get_name() const {
        return this->name;
    }

    const bool Parameters_base::get_is_restricted_to_cross() const {
        return this->is_restricted_to_cross;
    }

    const bool Parameters_base::get_is_restricted_to_build() const {
        return this->is_restricted_to_build;
    }

    const int Parameters_base::get_cost_to_cross() const {
        return this->cost_to_cross;
    }

    const Colour& Parameters_base::get_image_for_mini_map_id() const {
        return this->image_for_mini_map_id;
    }

    const Colour& Parameters_base::get_image_for_map_id() const {
        return this->image_for_map_id;
    }