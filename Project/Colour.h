#pragma once
#include <iostream>
class Colour {
	protected:
		int R = 0;
		int G = 0;
		int B = 0;
public:
    Colour();

    Colour(const int r, const int g, const int b);

    const int get_R() const;

    const int get_G() const;

    const int get_B() const;

    void set_R(const int r);

    void set_G(const int g);

    void set_B(const int b);
};