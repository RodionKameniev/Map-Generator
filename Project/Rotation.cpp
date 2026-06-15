#include "Rotation.h"
#include "Position.h"
#include <cmath> // Required for sin(), cos(), and round()

// Helper constant for PI
constexpr double PI = 3.14159265358979323846;

Position rotate_position(
    const Position& pos,
    Rotation rotation
)
{
    int x = pos.get_on_x();
    int y = pos.get_on_y();

    Position result = pos;
    double angle_deg = 0.0;
    bool use_trig = false;

    switch (rotation)
    {
    case Rotation::Deg0:
        return result;

    case Rotation::Deg45:
        angle_deg = 45.0;
        use_trig = true;
        break;

    case Rotation::Deg90:
        result.set_on_x(-y);
        result.set_on_y(x);
        return result;

    case Rotation::Deg135:
        angle_deg = 135.0;
        use_trig = true;
        break;

    case Rotation::Deg180:
        result.set_on_x(-x);
        result.set_on_y(-y);
        return result;

    case Rotation::Deg225:
        angle_deg = 225.0;
        use_trig = true;
        break;

    case Rotation::Deg270:
        result.set_on_x(y);
        result.set_on_y(-x);
        return result;

    case Rotation::Deg315:
        angle_deg = 315.0;
        use_trig = true;
        break;

    }


    if (use_trig)
    {
        // Convert degrees to radians
        double radians = angle_deg * (PI / 180.0);
        double cos_a = std::cos(radians);
        double sin_a = std::sin(radians);

        // Calculate new coordinates as doubles
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;

        // Round to nearest integer to prevent truncation errors
        result.set_on_x(static_cast<int>(std::round(new_x)));
        result.set_on_y(static_cast<int>(std::round(new_y)));
    }

    return result;
}