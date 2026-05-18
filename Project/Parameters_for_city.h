#include <iostream>
#include "Size_dimensional.h"
#include <string_view>
using namespace std;

class Parameters_for_city {
protected:
    string name="";
    Size_dimensional for_mini_map ;
    Size_dimensional for_map;
    
public:
    Parameters_for_city(string_view city_name, const Size_dimensional city_for_mini_map, const Size_dimensional city_for_map)
        : name(city_name), for_mini_map(city_for_mini_map), for_map(city_for_map) {
        cout << "Parameters_for_city is called" << std::endl;
    }

    // Set functions
    void set(string_view city_name, const Size_dimensional city_for_mini_map, const Size_dimensional city_for_map) {
        this->name = city_name;
        this->for_mini_map = city_for_mini_map;
        this->for_map = city_for_map;
    }
    void set_name(string_view city_name) {
        this->name = city_name;
    }
    void set_for_mini_map(const Size_dimensional city_for_mini_map) {
        this->for_mini_map = city_for_mini_map;
    }
    void set_for_map(const Size_dimensional city_for_map) {
        this->for_map = city_for_map;
    }

    // Get functions
    const string& get_name() const {
        return this->name;
    }
    const Size_dimensional get_for_mini_map() const {
        return this->for_mini_map;
    }
    const Size_dimensional get_for_map() const {
        return this->for_map;
    }
};
