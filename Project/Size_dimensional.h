#pragma once
#include <iostream>

class Size_dimensional {
protected:
    int size_x = 0;
    int size_y = 0;
    int size_z = 0;
public:
    Size_dimensional(const int x, const int y, const int z)
        : size_x(x), size_y(y), size_z(z) {
        //cout << "Size_dimensional is called" << std::endl;
    }

    // Set functions
    void set(const int x, const int y, const int z){
        this->size_x = x;
        this->size_y = y;
        this->size_z = z;
    }
    void set_size_x(const int x) {
        this->size_x = x;
    }
    void set_size_y(const int y) {
        this->size_y = y;
    }
    void set_size_z(const int z) {
        this->size_z = z;
    }

    // Get functions
    const int* get() const {
        int arr[3] = { this->size_x ,  this->size_y , this->size_z };
        return arr;
    }
    const int get_size_x() const {
        return this->size_x;
    }
    const int get_size_y() const {
        return this->size_y;
    }
    const int get_size_z() const {
        return this->size_z;
    }

};
