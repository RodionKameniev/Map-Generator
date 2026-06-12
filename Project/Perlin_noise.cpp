#include "Perlin_noise.h"

#include <random>
#include <time.h>
#include <iostream>
#include <cmath>

// -----------------------------------------------------------------------------
// Globals
// -----------------------------------------------------------------------------

unsigned long long g_seed = 0;

int WIDTH = 100;
int HEIGHT = 100;
float SCALE = 15.0f;

//static BITMAPINFO bitmapInfo;
std::pair<unsigned char*, int*> pixels_ground;
std::pair<unsigned char*, int*> pixels_river;
std::pair<unsigned char*, int*> pixels_to_output;

// -----------------------------------------------------------------------------
// Perlin Noise
// -----------------------------------------------------------------------------

vector2 randomGradient(int ix, int iy, unsigned long long seed)
{
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;

    unsigned a = (unsigned)(ix + seed);
    unsigned b = (unsigned)(iy + (seed >> 32));

    a *= 3284157443u;

    b ^= a << s | a >> (w - s);
    b *= 1911520717u;

    a ^= b << s | b >> (w - s);
    a *= 2048419325u;

    float random = a * (6.28318530718f / 4294967295.0f);

    vector2 v;

    v.x = sinf(random);
    v.y = cosf(random);

    return v;
}

float dotGridGradient(int ix, int iy, float x, float y, unsigned long long seed)
{
    vector2 gradient = randomGradient(ix, iy, seed);

    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return dx * gradient.x + dy * gradient.y;
}

float interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * (3.0f - w * 2.0f) * w * w + a0;
}

float perlin(float x, float y, unsigned long long seed)
{
    int x0 = (int)x;
    int y0 = (int)y;

    int x1 = x0 + 1;
    int y1 = y0 + 1;

    float sx = x - (float)x0;
    float sy = y - (float)y0;

    float n0 = dotGridGradient(x0, y0, x, y, seed);
    float n1 = dotGridGradient(x1, y0, x, y, seed);

    float ix0 = interpolate(n0, n1, sx);

    n0 = dotGridGradient(x0, y1, x, y, seed);
    n1 = dotGridGradient(x1, y1, x, y, seed);

    float ix1 = interpolate(n0, n1, sx);

    return interpolate(ix0, ix1, sy);
}

// -----------------------------------------------------------------------------
// Generate Noise
// -----------------------------------------------------------------------------

std::pair<unsigned char*, int*> GenerateNoise(std::pair<unsigned char*, int*> pixels, bool is_river, float base_contrast, float contrast_for_rivers, unsigned long long seed)
{
    //pixels.first = new unsigned char[WIDTH * HEIGHT * 4];
    pixels.second = new int[WIDTH * HEIGHT];
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            //int index = (y * WIDTH + x) * 4;
            int index_second = (y * WIDTH + x);

            float value = 0.0f;

            float freq = 1.0f;
            float amp = 1.0f;

            for (int i = 0; i < 10; i++)
            {
                value += perlin(
                    x * freq / SCALE,
                    y * freq / SCALE,
                    seed
                ) * amp;

                freq *= 2.0f;
                amp *= 0.5f;
            }

            value *= base_contrast;

            if (value > 1.2f) // 1.0
                value = 1.2f;

            if (value < -1.2f) // 1.0
                value = -1.2f;
            //int terrainValue = 0;
            int terrainValue = (int)(value * 280.0f); // 255
            /*if (terrainValue > 255) {
                terrainValue = 255;
            }*/
            if (terrainValue >= -100 and terrainValue < 50) { // 100 // 0
                terrainValue = 50; // 100 // 0
            }
            if (terrainValue < -100) { // -200 // 0
                terrainValue = -100; // -200 // 0
            }
            if (is_river) {
                terrainValue = abs((int)(value * contrast_for_rivers * 255.0f))-500.0f;
                if (terrainValue > 0) {
                    terrainValue = 0;
                }
                if (terrainValue < -300) {
                    terrainValue = -400;
                }

                /*terrainValue = abs((int)(value * contrast_for_rivers * 255.0f)) - 500.0f;
                if (terrainValue > 0) {
                    terrainValue = 0;
                }
                if (terrainValue < -300 and terrainValue > -500) {
                    terrainValue = -150;
                }
                else if (terrainValue > -300 and terrainValue < 0) {
                    terrainValue = -350;
                }*/
            }

            //unsigned char r = 0;
            //unsigned char g = 0;
            //unsigned char b = 0;

            //// Deep Water
            //if (terrainValue <= -200) // -200
            //{
            //    //std::cout << terrainValue;
            //    r = 0;
            //    g = 0;
            //    b = 80;
            //}
            //// Water
            //else if (terrainValue <= -50) //-50
            //{
            //    r = 30;
            //    g = 100;
            //    b = 220;
            //}
            //// Ground
            //else if (terrainValue <= 150) // 70
            //{
            //    r = 120;
            //    g = 200;
            //    b = 80;
            //}
            //// Forest
            //else if (terrainValue <= 220)
            //{
            //    r = 20;
            //    g = 120;
            //    b = 20;
            //}
            //// Mountain
            //else
            //{
            //    r = 140;
            //    g = 140;
            //    b = 140;
            //}
            //pixels.first[index + 0] = b;
            //pixels.first[index + 1] = g;
            //pixels.first[index + 2] = r;
            //pixels.first[index + 3] = 255;

            pixels.second[index_second] = terrainValue;
        }
    }
    return pixels;
}

// -----------------------------------------------------------------------------
// Window Procedure
// -----------------------------------------------------------------------------

//LRESULT CALLBACK WindowProc(
//    HWND hwnd,
//    UINT msg,
//    WPARAM wParam,
//    LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//
//        HDC hdc = BeginPaint(hwnd, &ps);
//
//        StretchDIBits(
//            hdc,
//            0,
//            0,
//            WIDTH,
//            HEIGHT,
//            0,
//            0,
//            WIDTH,
//            HEIGHT,
//            pixels_to_output.first,
//            &bitmapInfo,
//            DIB_RGB_COLORS,
//            SRCCOPY
//        );
//
//        EndPaint(hwnd, &ps);
//
//        return 0;
//    }
//
//    case WM_DESTROY:
//    {
//        PostQuitMessage(0);
//        return 0;
//    }
//    }
//
//    return DefWindowProc(hwnd, msg, wParam, lParam);
//}

// -----------------------------------------------------------------------------
// Run Window
// -----------------------------------------------------------------------------

int* RunPerlinWindow(
    unsigned long long seed,
    unsigned int width,
    unsigned int height,
    float scale)
{
    //clock_t tStart = clock();
    pixels_ground.first = nullptr;
    pixels_river.first = nullptr;
    pixels_to_output.first = nullptr;
    pixels_ground.second = nullptr;
    pixels_river.second = nullptr;
    pixels_to_output.second = nullptr;
    g_seed = seed;

    WIDTH = width;
    HEIGHT = height;
    SCALE = scale;

    pixels_ground = GenerateNoise(pixels_ground, false, 2.3f, 10.8f, seed);

    pixels_river = GenerateNoise(pixels_ground, true, 2.3f, 10.8f, seed << 16);
    pixels_to_output.first = new unsigned char[WIDTH * HEIGHT * 4];
    pixels_to_output.second = new int[WIDTH * HEIGHT];
    int* convolutioned_map = new int[WIDTH * HEIGHT];

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int index = (y * WIDTH + x) * 4;
            int index_second = (y * WIDTH + x);
            int terrainValue = pixels_ground.second[index_second] + pixels_river.second[index_second];
            if(x < WIDTH - 1){ // Baer–Babinet law https://en.wikipedia.org/wiki/Baer%E2%80%93Babinet_law
                terrainValue += (scale/10000.0f)*(pixels_ground.second[index_second + 1] + pixels_river.second[index_second + 1]);
            }
            //int terrainValue = pixels_river.second[index_second];
            unsigned char r = 0;
            unsigned char g = 0;
            unsigned char b = 0;

            if (terrainValue <= -300) {

                terrainValue += 150;

            }

            // Deep Water
            if (terrainValue <= -300) // -300
            {
                convolutioned_map[index_second] = -2;
                r = 0;
                g = 0;
                b = 80;
            }

            // Water
            else if (terrainValue <= -150) // -100
            {
                convolutioned_map[index_second] = -1;
                r = 30;
                g = 100;
                b = 220;
            }

            // Ground
            else if (terrainValue <= 70)
            {
                convolutioned_map[index_second] = 0;
                r = 120;
                g = 200;
                b = 80;
            }

            // Forest
            else if (terrainValue <= 220)
            {
                convolutioned_map[index_second] = 1;
                r = 20;
                g = 120;
                b = 20;
            }

            // Mountain
            else if(terrainValue <= 320) // 280 * 1.2
            {
                convolutioned_map[index_second] = 2;
                r = 140;
                g = 140;
                b = 140;
            }
            else {
                convolutioned_map[index_second] = 3;
                r = 180;
                g = 180;
                b = 180;
            }

            pixels_to_output.first[index + 0] = b;
            pixels_to_output.first[index + 1] = g;
            pixels_to_output.first[index + 2] = r;
            pixels_to_output.first[index + 3] = 255;
            pixels_to_output.second[index_second] = terrainValue;
        }
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    /*ZeroMemory(&bitmapInfo, sizeof(bitmapInfo));

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
    }*/
    return convolutioned_map;
    delete[] pixels_to_output.first;
    delete[] pixels_to_output.second;
    delete[] pixels_river.first;
    delete[] pixels_river.second;
    delete[] pixels_ground.first;
    delete[] pixels_ground.second;
}