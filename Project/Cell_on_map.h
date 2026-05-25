#pragma once
#include <iostream>
#include "Type_of_object.h"
#include "Position.h"

using namespace std;

class Cell_on_map {
protected:
    Position position;
    Type_of_object type_of_object;

public:
    Cell_on_map(
        const Position& position,
        const Type_of_object type_of_object
    )
        : position(position),
        type_of_object(type_of_object)
    {
        cout << "Cell_on_mini_map is called" << endl;
    }

    // Set functions
    void set(
        const Position& position,
        const Type_of_object type_of_object
    ) {
        this->position = position;
        this->type_of_object = type_of_object;
    }

    void set_position(const Position& position) {
        this->position = position;
    }

    void set_type_of_object(const Type_of_object type_of_object) {
        this->type_of_object = type_of_object;
    }

    // Get functions
    const Position& get_position() const {
        return this->position;
    }

    const Type_of_object get_type_of_object() const {
        return this->type_of_object;
    }
};