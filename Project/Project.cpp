#include <iostream>
#include <random>

#include <vector>

#include "Size_dimensional.h"
#include "Perlin_noise.h"
#include "Map.h"
#include "Colour.h"
#include "Position.h"

#include "Parameters_for_street.h"
#include "Street_component.h"
#include "Street_cluster.h"
#include "Street_cluster_spawn.h"

#include "Parameters_for_building.h"
#include "Building_component.h"
#include "Building_cluster.h"
#include "Building_cluster_spawn.h"

#include "Parameters_for_city.h"
#include "City.h"


using namespace std;

int main()
{
    /*Size_dimensional size_d(10, 20, 30);
    cout << size_d.get()[0] << '\n';
    cout << "Hello World!\n";
    cout << "TEST\n";*/
    srand(time(0));
    unsigned long long seed = rand();
    int height = 1000;
    int width = 1000;
    float b = 100.0;
    //Noise creation
    clock_t tStart = clock();

    int* map_in_vales = RunPerlinWindow(seed, width, height, 1.5f * b);

    printf("Noise taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    
    //Values assigment
    tStart = clock();

    Map new_map;
    new_map.create_base_map(map_in_vales, height, width);
    //Testing streets
    static Parameters_for_street crossed_parameters = Parameters_for_street("crossed_street_part", true, true, 10, 50, Colour(169, 169, 169), Colour(169, 169, 169));
    static Parameters_for_street straight_parameters = Parameters_for_street("straight_street_part", true, true, 10, 30, Colour(169, 169, 169), Colour(169, 169, 169));

    //Cross street
  
    static vector<Street_component> crossed_street_components;
    static vector<Position> crossed_street_next_streets;

    crossed_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    crossed_street_components.push_back(Street_component(&crossed_parameters, Position(2, 0, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(3, 0, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(4, 0, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(2, 1, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(2, 2, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(2, -1, 0)));
    crossed_street_components.push_back(Street_component(&straight_parameters, Position(2, -2, 0)));

    crossed_street_next_streets.push_back(Position(5, 0, 0));
    crossed_street_next_streets.push_back(Position(2, 3, 0));
    crossed_street_next_streets.push_back(Position(2, -3, 0));

    static Street_cluster crossed_street = Street_cluster(crossed_street_components, crossed_street_next_streets, 0.3);
    static Street_cluster_spawn crossed_street_spawn = Street_cluster_spawn(&crossed_street, 0.3);

    //Straight street

    static vector<Street_component> straight_street_components;
    static vector<Position> straight_street_next_streets;

    straight_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(2, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(3, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(4, 0, 0)));

    straight_street_next_streets.push_back(Position(5, 0, 0));

    static Street_cluster straight_street = Street_cluster(straight_street_components, straight_street_next_streets, 0.3);
    static Street_cluster_spawn straight_street_spawn = Street_cluster_spawn(&straight_street, 0.3);

    vector<Street_cluster_spawn> strets_to_spawn;
    strets_to_spawn.push_back(straight_street_spawn);
    strets_to_spawn.push_back(crossed_street_spawn);


    //Testing bildings

    static Parameters_for_building house_parameters = Parameters_for_building("house_part", 25, Colour(55, 55, 55), Colour(55, 55, 55));
    static Parameters_for_building station_parameters = Parameters_for_building("station_part", 50, Colour(148, 255, 234), Colour(148, 255, 234));

    //House building
    static vector<Building_component> house_building_components;

    house_building_components.push_back(Building_component(&house_parameters, Position(0, 0, 0)));

                    //house_building_components.size() * house_parameters.get_cost()

    static Building_cluster house_building = Building_cluster(house_building_components, 25, 0.8);
    static Building_cluster_spawn house_building_spawn = Building_cluster_spawn(&house_building, 0.8);

    //Station building
    static vector<Building_component> station_building_components;

    station_building_components.push_back(Building_component(&station_parameters, Position(0, 0, 0)));
    station_building_components.push_back(Building_component(&station_parameters, Position(1, 0, 0)));

    static Building_cluster station_building = Building_cluster(station_building_components, 50, 0.2);
    static Building_cluster_spawn station_building_spawn = Building_cluster_spawn(&station_building, 0.2);


    vector<Building_cluster> buildings;

    /*buildings.push_back(house_building);
    buildings.push_back(station_building);*/

    vector<Building_cluster_spawn> buildings_to_spawn;
    buildings_to_spawn.push_back(house_building_spawn);
    buildings_to_spawn.push_back(station_building_spawn);


    static Parameters_for_city parameters_for_city = Parameters_for_city("Mala Tokmachka", Size_dimensional(100, 100, 20), Size_dimensional(400, 400, 200));
    static City city = City(buildings, buildings_to_spawn, strets_to_spawn, parameters_for_city, 0, Position(500, 500, 0));

    city.create_city(new_map);

    new_map.render_map();

    return 0;
}