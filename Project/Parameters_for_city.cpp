#include "Parameters_for_city.h"
#include <iostream>
#include "Size_dimensional.h"
#include <string>
#include <string_view>
#include <string>
#include "random"

Parameters_for_city::Parameters_for_city(std::string_view city_name, const Size_dimensional& city_for_mini_map, const Size_dimensional& city_for_map):
    name(city_name), for_mini_map(city_for_mini_map), for_map(city_for_map){
        //std::cout << "Parameters_for_city is called"<< std::endl;
    }
int random_size()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(10, 100);

    return dist(gen);
}
Parameters_for_city::Parameters_for_city(std::string_view city_name) :
    name(city_name), for_mini_map(Size_dimensional(random_size(), random_size(), 0)), for_map(Size_dimensional(random_size(), random_size(), 0)) {
    //std::cout << "Parameters_for_city random is called" << std::endl;
}

    // Set functions
    void Parameters_for_city::set(
        std::string_view city_name,
        const Size_dimensional& city_for_mini_map,
        const Size_dimensional& city_for_map
    ) {
        this->name = city_name;

        this->for_mini_map =
            city_for_mini_map;

        this->for_map =
            city_for_map;
    }

    void Parameters_for_city::set_name(
        std::string_view city_name
    ) {
        this->name = city_name;
    }

    void Parameters_for_city::set_for_mini_map(
        const Size_dimensional& city_for_mini_map
    ) {
        this->for_mini_map =
            city_for_mini_map;
    }

    void Parameters_for_city::set_for_map(
        const Size_dimensional& city_for_map
    ) {
        this->for_map =
            city_for_map;
    }

    // Get functions
    const std::string& Parameters_for_city::get_name() const {
        return this->name;
    }

    const Size_dimensional&
        Parameters_for_city::get_for_mini_map() const {
        return this->for_mini_map;
    }

    const Size_dimensional&
        Parameters_for_city::get_for_map() const {
        return this->for_map;
    }