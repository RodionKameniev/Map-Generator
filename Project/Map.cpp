#include "Map.h"

#include <iostream>
#include <utility>

#include "City.h"

#include "Clutter_on_map.h"
#include "Street_on_map.h"
#include "Building_on_map.h"
#include "Parameters_for_clutter.h"
#include "Colour.h"

static BITMAPINFO bitmapInfo;
unsigned char* pixels_to_output = nullptr;

int render_width = 0;
int render_height = 0;
// Constructor
Map::Map()
    :
    size_of_mini_map(0, 0, 0),
    size_of_map(0, 0, 0),
    cells_on_mini_map(),
    cities(),
    clutters_probability_to_spawn()
{
    std::cout << "Empty Map is called" << std::endl;
}
Map::Map(
    const Size_dimensional& size_of_mini_map,
    const Size_dimensional& size_of_map,

    std::vector<
    std::vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map,

    std::vector<std::unique_ptr<City>> cities,

    const std::vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
)
    :
    size_of_mini_map(size_of_mini_map),

    size_of_map(size_of_map),

    cells_on_mini_map(
        move(cells_on_mini_map)
    ),

    cities(move(cities)),

    clutters_probability_to_spawn(
        clutters_probability_to_spawn
    )
{
    cout << "Map is called"
        << endl;
}

// Set functions
void Map::set(
    const Size_dimensional& size_of_mini_map,

    const Size_dimensional& size_of_map,

    std::vector<
    std::vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map,

    std::vector<std::unique_ptr<City>>cities,

    const std::vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
) {

    this->size_of_mini_map =
        size_of_mini_map;

    this->size_of_map =
        size_of_map;

    this->cells_on_mini_map =
        move(cells_on_mini_map);

    this->cities =
        move(cities);

    this->clutters_probability_to_spawn =
        clutters_probability_to_spawn;
}

void Map::set_size_of_mini_map(
    const Size_dimensional&
    size_of_mini_map
) {
    this->size_of_mini_map =
        size_of_mini_map;
}

void Map::set_size_of_map(
    const Size_dimensional&
    size_of_map
) {
    this->size_of_map =
        size_of_map;
}

void Map::set_cells_on_mini_map(
    std::vector<
    std::vector<
    unique_ptr<Cell_on_map>
    >
    > cells_on_mini_map
) {
    this->cells_on_mini_map =
        move(cells_on_mini_map);
}

void Map::set_cities(
    std::vector<std::unique_ptr<City>>cities
) {
    this->cities = move(cities);
}

void Map::
set_clutters_probability_to_spawn(
    const std::vector<
    Clutter_cluster_spawn
    >& clutters_probability_to_spawn
) {
    this->clutters_probability_to_spawn =
        clutters_probability_to_spawn;
}

// Get functions
const Size_dimensional&
Map::get_size_of_mini_map() const {
    return this->size_of_mini_map;
}

const Size_dimensional&
Map::get_size_of_map() const {
    return this->size_of_map;
}

const std::vector<
    std::vector<
    unique_ptr<Cell_on_map>
    >
>&
Map::get_cells_on_mini_map() const {
    return this->cells_on_mini_map;
}
std::vector<
    std::vector<
    unique_ptr<Cell_on_map>
    >
>&
Map::get_cells_on_mini_map(){
    return this->cells_on_mini_map;
}

const std::vector<std::unique_ptr<City>>&
Map::get_cities() const {
    return this->cities;
}

const std::vector<
    Clutter_cluster_spawn
>&
Map::
get_clutters_probability_to_spawn() const {
    return this->clutters_probability_to_spawn;
}

    // Functions

void Map::create_base_map(int* values, int height, int width) {
    this->set_size_of_mini_map(Size_dimensional(width, height, 0));
    render_height = height;
    render_width = width;
    this->cells_on_mini_map.clear();
    // 2 additional functions for map

    // Testing
    static Parameters_for_clutter deep_water = Parameters_for_clutter("Deep_water", Type_of_clutter::Water, true, true, 160, Colour(0, 0, 80), Colour(0, 0, 80));
    static Parameters_for_clutter water = Parameters_for_clutter("Water", Type_of_clutter::Water, true, true, 80, Colour(30, 100, 220), Colour(30, 100, 220));
    static Parameters_for_clutter ground = Parameters_for_clutter("Ground", Type_of_clutter::Ground, false, false, 10, Colour(120, 200, 80), Colour(120, 200, 80));
    static Parameters_for_clutter forest = Parameters_for_clutter("Forest", Type_of_clutter::Ground, false, false, 30, Colour(20, 120, 20), Colour(20, 120, 20));
    static Parameters_for_clutter mountain = Parameters_for_clutter("Mountain", Type_of_clutter::Mountain, true, true, 100, Colour(140, 140, 140), Colour(140, 140, 140));
    static Parameters_for_clutter high_mountain = Parameters_for_clutter("High_mountain", Type_of_clutter::Mountain, true, true, 200, Colour(180, 180, 180), Colour(180, 180, 180));
    static Parameters_for_clutter border = Parameters_for_clutter("Border", Type_of_clutter::Specific, true, true, 200, Colour(255, 0, 0), Colour(255, 0, 0));
    static const std::vector<Direction> no_connections;
    // Testing
    // Testing

    unique_ptr<Cell_on_map> cell_ptr;
    std::vector<unique_ptr<Cell_on_map>> cell_row;

    for (int x = 0; x <= width + 1; x++) {
        cell_ptr = make_unique<Clutter_on_map>(Position(x, 0, 0), &border, no_connections, 0);
        cell_ptr->set_type_of_object(Type_of_object::Border);
        cell_row.push_back(move(cell_ptr));
    }
    this->cells_on_mini_map.push_back(move(cell_row));
    cell_row = vector<unique_ptr<Cell_on_map>>();
    for (int y = 1; y <= height; y++) {

        cell_ptr = make_unique<Clutter_on_map>(Position(0, y, 0), &border, no_connections, 0);
        cell_ptr->set_type_of_object(Type_of_object::Border);
        cell_row.push_back(move(cell_ptr));

        for (int x = 1; x <= width; x++) {
            int index = ((y - 1) * width + (x - 1));
            
            if (values[index] == -2) { //Deep Water
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &deep_water, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else if (values[index] == -1) { //Water
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &water, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else if (values[index] == 0) { //Ground
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &ground, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else if (values[index] == 1) { //Forest
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &forest, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else if (values[index] == 2) { //Mountain
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &mountain, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else if (values[index] == 3) { //High Mountain
                cell_ptr = make_unique<Clutter_on_map>(Position(x, y, 0), &high_mountain, no_connections, 0);
                cell_row.push_back(move(cell_ptr));
            }
            else {
                throw runtime_error("Unknown terrain");
            }
        }

        unique_ptr<Cell_on_map> cell_ptr = make_unique<Clutter_on_map>(Position(width + 1, y, 0), &border, no_connections, 0);
        cell_ptr->set_type_of_object(Type_of_object::Border);
        cell_row.push_back(move(cell_ptr));

        this->cells_on_mini_map.push_back(move(cell_row));
        cell_row = std::vector<unique_ptr<Cell_on_map>>();
    }

    for (int x = 0; x <= width + 1; x++) {
        cell_ptr = make_unique<Clutter_on_map>(Position(x, height + 1, 0), &border, no_connections, 0);
        cell_ptr->set_type_of_object(Type_of_object::Border);
        cell_row.push_back(move(cell_ptr));
    }
    this->cells_on_mini_map.push_back(move(cell_row));
    cell_row = std::vector<unique_ptr<Cell_on_map>>();
    // Testing
}

void Map::add_city(std::unique_ptr<City> city_to_add) {
    cities.push_back(std::move(city_to_add));
}

LRESULT CALLBACK Map::WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam
)
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
            render_width,
            render_height,
            0,
            0,
            render_width,
            render_height,
            pixels_to_output,
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

void Map::render_map()
{
    render_height =
        this->get_size_of_mini_map().get_size_y();

    render_width =
        this->get_size_of_mini_map().get_size_x();

    pixels_to_output =
        new unsigned char[
            render_width *
                render_height *
                4
        ];
    std::cout << render_height << " " << render_width << std::endl;
    std::cout << render_width *
        render_height *
        4 << std::endl;
    std::cout << cells_on_mini_map.size() << " " << cells_on_mini_map[0].size() << std::endl;
    // Fill pixels from map
    for (int y = 0; y < render_height; y++)
    {
        for (int x = 0; x < render_width; x++)
        {
            int index =
                (y * render_width + x) * 4;

            /*std::cout << y << " " << x << std::endl;
            std::cout << "pixels_to_output: " << index << std::endl;
            std::cout << "cells_on_mini_map: " << y + 1 << " " << x + 1 << std::endl;*/
            Cell_on_map* cell =
                this->cells_on_mini_map[y+1][x+1].get();

            if (dynamic_cast<Clutter_on_map*>(cell)) {
                Clutter_on_map* clutter =
                    dynamic_cast<Clutter_on_map*>(cell);

                if (clutter->get_type_of_object() != Type_of_object::Border && clutter != nullptr &&
                    clutter->get_clutter_to_be_placed() != nullptr)
                {
                    Colour colour =
                        clutter
                        ->get_clutter_to_be_placed()
                        ->get_image_for_map_id();

                    pixels_to_output[index + 0] =
                        colour.get_B();

                    pixels_to_output[index + 1] =
                        colour.get_G();

                    pixels_to_output[index + 2] =
                        colour.get_R();

                    pixels_to_output[index + 3] =
                        255;
                }
                else {
                    pixels_to_output[index + 0] = 0;
                    pixels_to_output[index + 1] = 0;
                    pixels_to_output[index + 2] = 0;
                    pixels_to_output[index + 3] = 255;
                }
            }
            else
            {
                if (dynamic_cast<Street_on_map*>(cell)) {
                    Street_on_map* street =
                        dynamic_cast<Street_on_map*>(cell);

                    if (street != nullptr &&
                        street->get_street_to_be_placed() != nullptr)
                    {
                        Colour colour =
                            street
                            ->get_street_to_be_placed()
                            ->get_image_for_map_id();

                        pixels_to_output[index + 0] =
                            colour.get_B();

                        pixels_to_output[index + 1] =
                            colour.get_G();

                        pixels_to_output[index + 2] =
                            colour.get_R();

                        pixels_to_output[index + 3] =
                            255;
                    }
                }
                else
                {
                    if (dynamic_cast<Building_on_map*>(cell)) {
                        Building_on_map* building =
                            dynamic_cast<Building_on_map*>(cell);

                        if (building != nullptr &&
                            building->get_building_to_be_placed() != nullptr)
                        {
                            Colour colour =
                                building
                                ->get_building_to_be_placed()
                                ->get_image_for_map_id();

                            pixels_to_output[index + 0] =
                                colour.get_B();

                            pixels_to_output[index + 1] =
                                colour.get_G();

                            pixels_to_output[index + 2] =
                                colour.get_R();

                            pixels_to_output[index + 3] =
                                255;
                        }
                    }
                }
                
            }
        }
    }

    ZeroMemory(&bitmapInfo, sizeof(bitmapInfo));

    bitmapInfo.bmiHeader.biSize =
        sizeof(BITMAPINFOHEADER);

    bitmapInfo.bmiHeader.biWidth =
        render_width;

    bitmapInfo.bmiHeader.biHeight =
        -render_height;

    bitmapInfo.bmiHeader.biPlanes = 1;

    bitmapInfo.bmiHeader.biBitCount = 32;

    bitmapInfo.bmiHeader.biCompression =
        BI_RGB;

    HINSTANCE hInstance =
        GetModuleHandle(NULL);

    const wchar_t CLASS_NAME[] =
        L"MapWindowClass";

    WNDCLASS wc = {};

    wc.lpfnWndProc = Map::WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Map Renderer",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        render_width,
        render_height,
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

    delete[] pixels_to_output;
}

