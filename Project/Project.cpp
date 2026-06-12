#include <iostream>
#include <random>

#include "Size_dimensional.h"
#include "Perlin_noise.h"
#include "Map.h"
using namespace std;

int main()
{
    /*Size_dimensional size_d(10, 20, 30);
    cout << size_d.get()[0] << '\n';
    cout << "Hello World!\n";
    cout << "TEST\n";*/
    srand(time(0));
    unsigned long long seed = rand();
    int height = 1080;
    int width = 1920;
    float b = 50.0;
    
    //Noise creation
    clock_t tStart = clock();

    int* map_in_vales = RunPerlinWindow(seed, width, height, 1.5f*b);
    
    printf("Noise taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    
    //Values assigment
    tStart = clock();

    Map new_map;
    new_map.create_base_map(map_in_vales, height, width);
    
    printf("Map creation time: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    //Render
    
    new_map.render_map();

    return 0;
}