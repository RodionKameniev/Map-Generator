#pragma once

#include "Position.h"

enum class Rotation
{
    Deg0,
    Deg90,
    Deg180,
    Deg270
};

Position rotate_position(
    const Position& pos,
    Rotation rotation
);