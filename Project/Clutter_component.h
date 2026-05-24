#include <iostream>

#include "Parameters_for_clutter.h"
#include "Position.h"

using namespace std;

class Clutter_component {
protected:
    const Parameters_for_clutter* clutter_part;

    Position shifted_position;

public:
    Clutter_component(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    )
        :
        clutter_part(clutter_part),
        shifted_position(shifted_position)
    {
        cout << "Clutter_component is called"
            << endl;
    }

    // Set functions
    void set(
        const Parameters_for_clutter* clutter_part,
        const Position& shifted_position
    ) {
        this->clutter_part =
            clutter_part;

        this->shifted_position =
            shifted_position;
    }

    void set_clutter_part(
        const Parameters_for_clutter* clutter_part
    ) {
        this->clutter_part =
            clutter_part;
    }

    void set_shifted_position(
        const Position& shifted_position
    ) {
        this->shifted_position =
            shifted_position;
    }

    // Get functions
    const Parameters_for_clutter*
        get_clutter_part() const {
        return this->clutter_part;
    }

    const Position&
        get_shifted_position() const {
        return this->shifted_position;
    }
};
