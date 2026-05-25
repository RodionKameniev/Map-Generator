#pragma once
#include <iostream>
using namespace std;

class Position {
protected:
    int on_x = 0;
    int on_y = 0;
    int on_z = 0;
public:
    Position(const int x, const int y, const int z)
        : on_x(x), on_y(y), on_z(z) {
        cout << "Position is called" << std::endl;
    }

    // Set functions
    void set(const int x, const int y, const int z) {
        this->on_x = x;
        this->on_y = y;
        this->on_z = z;
    }
    void set_on_x(const int x) {
        this->on_x = x;
    }
    void set_on_y(const int y) {
        this->on_y = y;
    }
    void set_on_z(const int z) {
        this->on_z = z;
    }

    // Get functions
    const int* get() const {
        int arr[3] = { this->on_x ,  this->on_y , this->on_z };
        return arr;
    }
    const int get_on_x() const {
        return this->on_x;
    }
    const int get_on_y() const {
        return this->on_y;
    }
    const int get_on_z() const {
        return this->on_z;
    }

};
