#include <iostream>

#include "Parameters_for_building.h"
#include "Position.h"

using namespace std;

class Building_component {
protected:
    const Parameters_for_building* buiding_part;

    Position shifted_position;

public:
    Building_component(
        const Parameters_for_building* buiding_part,
        const Position& shifted_position
    )
        :
        buiding_part(buiding_part),
        shifted_position(shifted_position)
    {
        cout << "Building_component is called"
            << endl;
    }

    // Set functions
    void set(
        const Parameters_for_building* buiding_part,
        const Position& shifted_position
    ) {
        this->buiding_part =
            buiding_part;

        this->shifted_position =
            shifted_position;
    }

    void set_buiding_part(
        const Parameters_for_building* buiding_part
    ) {
        this->buiding_part =
            buiding_part;
    }

    void set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_building*
        get_buiding_part() const {
        return this->buiding_part;
    }

    const Position&
        get_shifted_position() const {
        return this->shifted_position;
    }
};