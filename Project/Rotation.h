#pragma once

#include "Position.h"

enum class Rotation
{
    Deg0,
    Deg45,
    Deg90,
    Deg135,
    Deg180,
    Deg225,
    Deg270,
    Deg315
};

Position rotate_position(
    const Position& pos,
    Rotation rotation
);