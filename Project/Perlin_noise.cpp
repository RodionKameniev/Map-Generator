#include <iostream>
#include "Perlin_noise.h"
#include <windows.h>
#include <cmath>

// -----------------------------------------------------------------------------
// Perlin Noise
// -----------------------------------------------------------------------------

typedef struct
{
    float x, y;
} vector2;

// Global seed
unsigned long long g_seed = 0;
unsigned long long r_seed = 0;

vector2 randomGradient(int ix, int iy)
{
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;

    // Mix seed into coordinates
    unsigned a = (unsigned)(ix + g_seed);
    unsigned b = (unsigned)(iy + (g_seed >> 32));

    a *= 3284157443u;

    b ^= a << s | a >> (w - s);
    b *= 1911520717u;

    a ^= b << s | b >> (w - s);
    a *= 2048419325u;

    // Convert to angle [0, 2PI]
    float random = a * (6.28318530718f / 4294967295.0f);

    vector2 v;

    v.x = sinf(random);
    v.y = cosf(random);

    return v;
}

float dotGridGradient(int ix, int iy, float x, float y)
{
    vector2 gradient = randomGradient(ix, iy);

    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return (dx * gradient.x + dy * gradient.y);
}

float interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * (3.0f - w * 2.0f) * w * w + a0;
}

float perlin(float x, float y)
{
    int x0 = (int)x;
    int y0 = (int)y;

    int x1 = x0 + 1;
    int y1 = y0 + 1;

    float sx = x - (float)x0;
    float sy = y - (float)y0;

    float n0 = dotGridGradient(x0, y0, x, y);
    float n1 = dotGridGradient(x1, y0, x, y);

    float ix0 = interpolate(n0, n1, sx);

    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);

    float ix1 = interpolate(n0, n1, sx);

    return interpolate(ix0, ix1, sy);
}

// -----------------------------------------------------------------------------
// Globals
// -----------------------------------------------------------------------------

int WIDTH = 100;
int HEIGHT = 100;
float SCALE = 15.0f;
int NUMBER_OF_OBJECTS = 6;

BITMAPINFO bitmapInfo;
unsigned char* pixels = nullptr;

// -----------------------------------------------------------------------------
// Generate Noise Texture
// -----------------------------------------------------------------------------

void GenerateNoise()
{
    pixels = new unsigned char[WIDTH * HEIGHT * 4];

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int index = (y * WIDTH + x) * 4;

            float value = 0.0f;
            float freq = 1.0f;
            float amp = 1.0f;
            // Octaves
            for (int i = 0; i < 6; i++)
            {
                value += perlin(
                    x * freq / SCALE,
                    y * freq / SCALE
                ) * amp;
                freq *= 2.0f;
                amp *= 0.5f;
            }
            // Contrast
            //value *= 1.2f;
            value *= 2.3f;

            //float value = 0.0f;

            //float freq = 1.0f;
            //float amp = 1.0f;

            //float maxValue = 0.0f;

            //for (int i = 0; i < 6; i++)
            //{
            //    value += perlin(
            //        x * freq / SCALE,
            //        y * freq / SCALE
            //    ) * amp;

            //    maxValue += amp;

            //    freq *= 2.0f;
            //    amp *= 0.5f;
            //}

            //// Normalize to [-1,1]
            //value /= maxValue;

            //std::cout << value << "\t";

            // Clamp
            if (value > 1.0f)
                value = 1.0f;

            if (value < -1.0f)
                value = -1.0f;

            //int color = (int)(((value + 1.0f) * 0.5f) * 255.0f);

            // BGRA
            /*pixels[index + 0] = color;
            pixels[index + 1] = color;
            pixels[index + 2] = color;
            pixels[index + 3] = 255;*/

            // Convert value from [-1,1] to [-255,255]
            int terrainValue = (int)(value * 255.0f);

            // Default color
            unsigned char r = 0;
            unsigned char g = 0;
            unsigned char b = 0;

            // --------------------------------------------------
            // TERRAIN COLOR RANGES
            // --------------------------------------------------

            // Deep water
            if (terrainValue >= -255 && terrainValue <= -200)
            {
                r = 0;
                g = 0;
                b = 80;
            }

            // Water
            else if (terrainValue >= -199 && terrainValue <= -50)
            {
                r = 30;
                g = 100;
                b = 220;
            }

            // Ground
            else if (terrainValue >= -49 && terrainValue <= 70)
            {
                r = 120;
                g = 200;
                b = 80;
            }

            // Forest
            else if (terrainValue >= 71 && terrainValue <= 220)
            {
                r = 20;
                g = 120;
                b = 20;
            }

            // Mountain
            else if (terrainValue >= 221 && terrainValue <= 255)
            {
                r = 140;
                g = 140;
                b = 140;
            }

            // BGRA format
            pixels[index + 0] = b;
            pixels[index + 1] = g;
            pixels[index + 2] = r;
            pixels[index + 3] = 255;
            
           
        }
    }

    //for (int x = 0; x < WIDTH; x++) {
    //    for (int y = 0; y < HEIGHT; y++) {
    //        int index = (y * WIDTH + x) * 4;
    //        std::cout << (int)pixels[index] << "\t";
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;
    //for (int x = 0; x < WIDTH; x++) {
    //    for (int y = 0; y < HEIGHT; y++) {
    //        int index = (y * WIDTH + x) * 4;
    //        float number = (((int)pixels[index] - 127) / (float)255) * (float)NUMBER_OF_OBJECTS;
    //        int cropped_number = round(number);
    //        std::cout << cropped_number << "\t";
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;
    //for (int x = 0; x < WIDTH; x++) {
    //    for (int y = 0; y < HEIGHT; y++) {
    //        int index = (y * WIDTH + x) * 4;
    //        float number = (((int)pixels[index] - 127) / (float)255) * (float)NUMBER_OF_OBJECTS;
    //        int cropped_number = round(number);
    //        if (cropped_number == -3 || cropped_number == -2) {
    //            std::cout << "d_water" << "\t";
    //        }
    //        if (cropped_number == -1) {
    //            std::cout << "water" << "\t";
    //        }
    //        if (cropped_number == 0) {
    //            std::cout << "ground" << "\t";
    //        }
    //        if (cropped_number == 1) {
    //            std::cout << "forest" << "\t";
    //        }
    //        if (cropped_number == 2) {
    //            std::cout << "mountain" << "\t";
    //        }
    //        //std::cout << cropped_number << "\t";
    //    }
    //    std::cout << std::endl;
    //}
}

// -----------------------------------------------------------------------------
// Window Procedure
// -----------------------------------------------------------------------------

LRESULT CALLBACK WindowProc(HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(hwnd, &ps);

        StretchDIBits(
            hdc,
            0,
            0,
            WIDTH,
            HEIGHT,
            0,
            0,
            WIDTH,
            HEIGHT,
            pixels,
            &bitmapInfo,
            DIB_RGB_COLORS,
            SRCCOPY
        );

        EndPaint(hwnd, &ps);

        return 0;
    }

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// -----------------------------------------------------------------------------
// Run Window
// -----------------------------------------------------------------------------

void RunPerlinWindow(unsigned long long seed, unsigned int width, unsigned int height, float scale)
{
    // Store seed globally
    g_seed = seed;
    WIDTH = width;
    HEIGHT = height;
    SCALE = scale;
    GenerateNoise();

    ZeroMemory(&bitmapInfo, sizeof(bitmapInfo));

    bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biWidth = WIDTH;
    bitmapInfo.bmiHeader.biHeight = -HEIGHT;
    bitmapInfo.bmiHeader.biPlanes = 1;
    bitmapInfo.bmiHeader.biBitCount = 32;
    bitmapInfo.bmiHeader.biCompression = BI_RGB;

    HINSTANCE hInstance = GetModuleHandle(NULL);

    const wchar_t CLASS_NAME[] = L"PerlinWindow";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Perlin Noise",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        WIDTH,
        HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    delete[] pixels;
}