#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX


#include <windows.h>
#include <utility>

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

//extern unsigned long long g_seed;
//
//extern int WIDTH;
//extern int HEIGHT;
//extern float SCALE;
//
//extern BITMAPINFO bitmapInfo;
//extern unsigned char* pixels;

// -----------------------------------------------------------------------------
// Function Declarations
// -----------------------------------------------------------------------------

vector2 randomGradient(int ix, int iy, unsigned long long seed);

float dotGridGradient(int ix, int iy, float x, float y, unsigned long long seed);

float interpolate(float a0, float a1, float w);

float perlin(float x, float y, unsigned long long seed);

std::pair<unsigned char*, int*> GenerateNoise(std::pair<unsigned char*, int*> pixels, bool is_river, float base_contrast, float contrast_for_rivers, unsigned long long seed);

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
);

int* RunPerlinWindow(
    unsigned long long seed,
    unsigned int width,
    unsigned int height,
    float scale
);