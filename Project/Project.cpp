#include <iostream>
#include <random>

#include "Size_dimensional.h"
#include "Perlin_noise.h"
using namespace std;

int main()
{
    /*Size_dimensional size_d(10, 20, 30);
    cout << size_d.get()[0] << '\n';
    cout << "Hello World!\n";
    cout << "TEST\n";*/
    srand(time(0));
    unsigned long long seed = rand();
    int a = 1000;
    float b = 100.0;
    
    RunPerlinWindow(seed, a, a, 1.5f*b);
    
    return 0;
}