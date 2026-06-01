#pragma once
#include <iostream>
#include "Type_of_object.h"
#include "Position.h"

class Cell_on_map {
protected:
    Position position;
    Type_of_object type_of_object;

public:

    virtual ~Cell_on_map() = default;

    Cell_on_map(
        const Position& position,
        const Type_of_object type_of_object
    );

    // Set functions
    void set(
        const Position& position,
        const Type_of_object type_of_object
    );

    void set_position(const Position& position);

    void set_type_of_object(const Type_of_object type_of_object);

    // Get functions
    const Position& get_position() const;

    const Type_of_object get_type_of_object() const;
};