#include "Cell_on_map.h"

#include <iostream>
#include "Type_of_object.h"
#include "Position.h"

Cell_on_map::Cell_on_map(
    const Position& position,
    const Type_of_object type_of_object
)
    : position(position),
    type_of_object(type_of_object)
{
    //std::cout << "Cell_on_mini_map is called" << std::endl;
}

// Set functions
void Cell_on_map::set(
    const Position& position,
    const Type_of_object type_of_object
) {
    this->position = position;
    this->type_of_object = type_of_object;
}

void Cell_on_map::set_position(const Position& position) {
    this->position = position;
}

void Cell_on_map::set_type_of_object(const Type_of_object type_of_object) {
    this->type_of_object = type_of_object;
}

// Get functions
const Position& Cell_on_map::get_position() const {
    return this->position;
}

const Type_of_object Cell_on_map::get_type_of_object() const {
    return this->type_of_object;
}