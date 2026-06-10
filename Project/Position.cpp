#include "Position.h"
#include <iostream>


Position::Position(const int x, const int y, const int z)
        : on_x(x), on_y(y), on_z(z) {
        //cout << "Position is called" << std::endl;
    }
    bool Position::operator<(const Position& other) const {
        return std::tie(on_x, on_y, on_z) < std::tie(other.on_x, other.on_y, other.on_z);
    }

    // Set functions
    void Position::set_all(const int x, const int y, const int z) {
        this->on_x = x;
        this->on_y = y;
        this->on_z = z;
    }
    void Position::set_on_x(const int x) {
        this->on_x = x;
    }
    void Position::set_on_y(const int y) {
        this->on_y = y;
    }
    void Position::set_on_z(const int z) {
        this->on_z = z;
    }

    // Get functions
    const int* Position::get() const {
        int arr[3] = { this->on_x ,  this->on_y , this->on_z };
        return arr;
    }
    const int Position::get_on_x() const {
        return this->on_x;
    }
    const int Position::get_on_y() const {
        return this->on_y;
    }
    const int Position::get_on_z() const {
        return this->on_z;
    }
