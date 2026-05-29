#pragma once
#include <iostream>
class Colour {
	protected:
		int R = 0;
		int G = 0;
		int B = 0;
public:
    Colour() : R(0), G(0), B(0) {}

    Colour(const int r, const int g, const int b) : R(r), G(g), B(b) {}

    const int get_R() const {
        return R;
    }

    const int get_G() const {
        return G;
    }

    const int get_B() const {
        return B;
    }

    void set_R(const int r) {
        R = r;
    }

    void set_G(const int g) {
        G = g;
    }

    void set_B(const int b) {
        B = b;
    }
};