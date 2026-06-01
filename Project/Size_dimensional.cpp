#include "Size_dimensional.h"
#include <iostream>


Size_dimensional::Size_dimensional(const int x, const int y, const int z)
        : size_x(x), size_y(y), size_z(z) {
        //cout << "Size_dimensional is called" << std::endl;
    }

    // Set functions
    void Size_dimensional::set(const int x, const int y, const int z) {
        this->size_x = x;
        this->size_y = y;
        this->size_z = z;
    }
    void Size_dimensional::set_size_x(const int x) {
        this->size_x = x;
    }
    void Size_dimensional::set_size_y(const int y) {
        this->size_y = y;
    }
    void Size_dimensional::set_size_z(const int z) {
        this->size_z = z;
    }

    // Get functions
    const int* Size_dimensional::get() const {
        int arr[3] = { this->size_x ,  this->size_y , this->size_z };
        return arr;
    }
    const int Size_dimensional::get_size_x() const {
        return this->size_x;
    }
    const int Size_dimensional::get_size_y() const {
        return this->size_y;
    }
    const int Size_dimensional::get_size_z() const {
        return this->size_z;
    }
