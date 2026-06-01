#include "Colour.h"
#include <iostream>

Colour::Colour() : R(0), G(0), B(0) {}

Colour::Colour(const int r, const int g, const int b) : R(r), G(g), B(b) {}

    const int Colour::get_R() const {
        return R;
    }

    const int Colour::get_G() const {
        return G;
    }

    const int Colour::get_B() const {
        return B;
    }

    void Colour::set_R(const int r) {
        R = r;
    }

    void Colour::set_G(const int g) {
        G = g;
    }

    void Colour::set_B(const int b) {
        B = b;
    }