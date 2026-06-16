#include "Street_component.h"

#include <iostream>
#include "Parameters_for_street.h"
#include "Position.h"


Street_component::Street_component(
    const Parameters_for_street* street_part,
    const Position& shifted_position
)
    :
    street_part(street_part),
    shifted_position(shifted_position)
{
    //std::cout << "Street_component is called" << std::endl;
}

// Set functions
void  Street_component::set(
    const Parameters_for_street* street_part,
    const Position& shifted_position
) {
    this->street_part =
        street_part;

    this->shifted_position =
        shifted_position;
}

void Street_component::set_street_part(
    const Parameters_for_street* street_part
) {
    this->street_part =
        street_part;
}

void Street_component::set_shifted_position(
    const Position& shifted_position
) {
    this->shifted_position =
        shifted_position;
}

// Get functions
const Parameters_for_street*
Street_component::get_street_part() const {
    return this->street_part;
}

const Position&
Street_component::get_shifted_position() const {
    return this->shifted_position;
}