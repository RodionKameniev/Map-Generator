#include <iostream>
#include "Size_dimensional.h"
#include "Perlin_noise.h"
using namespace std;

int main()
{
    /*Size_dimensional size_d(10, 20, 30);
    cout << size_d.get()[0] << '\n';
    cout << "Hello World!\n";
    cout << "TEST\n";*/
    unsigned long long seed = 1;

    RunPerlinWindow(seed, 100, 100, 15.0f);

    return 0;
}