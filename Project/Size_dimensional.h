#pragma once
#include <iostream>

class Size_dimensional {
protected:
    int size_x = 0;
    int size_y = 0;
    int size_z = 0;
public:
    Size_dimensional(const int x, const int y, const int z);

    // Set functions
    void set(const int x, const int y, const int z);
    void set_size_x(const int x);
    void set_size_y(const int y);
    void set_size_z(const int z);

    // Get functions
    const int* get() const;
    const int get_size_x() const;
    const int get_size_y() const;
    const int get_size_z() const;

};
