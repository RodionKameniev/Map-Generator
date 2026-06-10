#pragma once
#include <iostream>

class Position {
protected:
    int on_x = 0;
    int on_y = 0;
    int on_z = 0;
public:
    Position(const int x, const int y, const int z);
    bool operator<(const Position& other) const;

    // Set functions
    void set_all(const int x, const int y, const int z);
    void set_on_x(const int x);
    void set_on_y(const int y);
    void set_on_z(const int z);

    // Get functions
    const int* get() const;
    const int get_on_x() const;
    const int get_on_y() const;
    const int get_on_z() const;

};
