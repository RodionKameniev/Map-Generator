#include "Rotation.h"

#include "Position.h"

Position rotate_position(
    const Position& pos,
    Rotation rotation
)
{
    int x = pos.get_on_x();
    int y = pos.get_on_y();
    int z = pos.get_on_y();

    Position result = pos;

    switch (rotation)
    {
    case Rotation::Deg0:
        break;

    case Rotation::Deg90:
        result.set_on_x(-y);
        result.set_on_y(x);
        break;

    case Rotation::Deg180:
        result.set_on_x(-x);
        result.set_on_y(-y);
        break;

    case Rotation::Deg270:
        result.set_on_x(y);
        result.set_on_y(-x);
        break;
    }

    return result;
}