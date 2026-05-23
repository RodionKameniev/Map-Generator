#include <iostream>

#include "Parameters_for_street.h"
#include "Position.h"

using namespace std;

class Street_component {
protected:
    const Parameters_for_street* street_part;

    Position shifted_position;

public:
    Street_component(
        const Parameters_for_street* street_part,
        const Position& shifted_position
    )
        :
        street_part(street_part),
        shifted_position(shifted_position)
    {
        cout << "Street_component is called"
            << endl;
    }

    // Set functions
    void set(
        const Parameters_for_street* street_part,
        const Position& shifted_position
    ) {
        this->street_part =
            street_part;

        this->shifted_position =
            shifted_position;
    }

    void set_street_part(
        const Parameters_for_street* street_part
    ) {
        this->street_part =
            street_part;
    }

    void set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_street*
        get_street_part() const {
        return this->street_part;
    }

    const Position&
        get_shifted_position() const {
        return this->shifted_position;
    }
};