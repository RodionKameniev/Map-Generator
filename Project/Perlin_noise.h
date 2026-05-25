#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX


#include <windows.h>


// -----------------------------------------------------------------------------
// Structs
// -----------------------------------------------------------------------------

struct vector2
{
    float x;
    float y;
};

// -----------------------------------------------------------------------------
// Extern Globals
// -----------------------------------------------------------------------------

extern unsigned long long g_seed;

extern int WIDTH;
extern int HEIGHT;
extern float SCALE;

extern BITMAPINFO bitmapInfo;
extern unsigned char* pixels;

// -----------------------------------------------------------------------------
// Function Declarations
// -----------------------------------------------------------------------------

vector2 randomGradient(int ix, int iy);

float dotGridGradient(int ix, int iy, float x, float y);

float interpolate(float a0, float a1, float w);

float perlin(float x, float y);

void GenerateNoise();

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
);

void RunPerlinWindow(
    unsigned long long seed,
    unsigned int width,
    unsigned int height,
    float scale
);