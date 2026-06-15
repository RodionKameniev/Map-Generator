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

#include "Type_of_clutter.h"

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
    static Parameters_for_street crossed_parameters = Parameters_for_street("crossed_street_part", true, true, false, 10, 50, Colour(169, 169, 169), Colour(169, 169, 169));
    static Parameters_for_street straight_parameters = Parameters_for_street("straight_street_part", true, true, false, 10, 30, Colour(169, 169, 169), Colour(169, 169, 169));
    static Parameters_for_street to_left_parameters = Parameters_for_street("to_left_street_part", true, true, false, 10, 35, Colour(169, 169, 169), Colour(169, 169, 169));
    static Parameters_for_street to_right_parameters = Parameters_for_street("to_right_street_part", true, true, false, 10, 35, Colour(169, 169, 169), Colour(169, 169, 169));
    static Parameters_for_street t_shaped_parameters = Parameters_for_street("t_shaped_street_part", true, true, false, 10, 35, Colour(169, 169, 169), Colour(169, 169, 169));

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

    static Street_cluster crossed_street = Street_cluster(crossed_street_components, crossed_street_next_streets, 0.5);
    static Street_cluster_spawn crossed_street_spawn = Street_cluster_spawn(&crossed_street, 0.5);

    //Straight street

    static vector<Street_component> straight_street_components;
    static vector<Position> straight_street_next_streets;

    straight_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(2, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(3, 0, 0)));
    straight_street_components.push_back(Street_component(&straight_parameters, Position(4, 0, 0)));

    straight_street_next_streets.push_back(Position(5, 0, 0));

    static Street_cluster straight_street = Street_cluster(straight_street_components, straight_street_next_streets, 0.8);
    static Street_cluster_spawn straight_street_spawn = Street_cluster_spawn(&straight_street, 0.8);

    //To left street

    static vector<Street_component> to_left_street_components;
    static vector<Position> to_left_street_next_streets;

    to_left_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    to_left_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    to_left_street_components.push_back(Street_component(&straight_parameters, Position(2, 0, 0)));
    to_left_street_components.push_back(Street_component(&to_left_parameters, Position(3, 0, 0)));
    to_left_street_components.push_back(Street_component(&straight_parameters, Position(3, 1, 0)));
    to_left_street_components.push_back(Street_component(&straight_parameters, Position(3, 2, 0)));
    to_left_street_components.push_back(Street_component(&straight_parameters, Position(3, 3, 0)));

    to_left_street_next_streets.push_back(Position(3, 4, 0));

    static Street_cluster to_left_street = Street_cluster(to_left_street_components, to_left_street_next_streets, 0.2);
    static Street_cluster_spawn to_left_street_spawn = Street_cluster_spawn(&to_left_street, 0.2);

    //To right street

    static vector<Street_component> to_right_street_components;
    static vector<Position> to_right_street_next_streets;

    to_right_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    to_right_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    to_right_street_components.push_back(Street_component(&straight_parameters, Position(2, 0, 0)));
    to_right_street_components.push_back(Street_component(&to_right_parameters, Position(3, 0, 0)));
    to_right_street_components.push_back(Street_component(&straight_parameters, Position(3, -1, 0)));
    to_right_street_components.push_back(Street_component(&straight_parameters, Position(3, -2, 0)));
    to_right_street_components.push_back(Street_component(&straight_parameters, Position(3, -3, 0)));

    to_right_street_next_streets.push_back(Position(3, -4, 0));

    static Street_cluster to_right_street = Street_cluster(to_right_street_components, to_right_street_next_streets, 0.2);
    static Street_cluster_spawn to_right_street_spawn = Street_cluster_spawn(&to_right_street, 0.2);

    //T shaped street

    static vector<Street_component> t_shaped_street_components;
    static vector<Position> t_shaped_street_next_streets;

    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(0, 0, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(1, 0, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(2, 0, 0)));
    t_shaped_street_components.push_back(Street_component(&t_shaped_parameters, Position(3, 0, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, -1, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, -2, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, -3, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, 1, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, 2, 0)));
    t_shaped_street_components.push_back(Street_component(&straight_parameters, Position(3, 3, 0)));


    t_shaped_street_next_streets.push_back(Position(3, -4, 0));
    t_shaped_street_next_streets.push_back(Position(3, 4, 0));

    static Street_cluster t_shaped_street = Street_cluster(t_shaped_street_components, t_shaped_street_next_streets, 0.2);
    static Street_cluster_spawn t_shaped_street_spawn = Street_cluster_spawn(&t_shaped_street, 0.2);


    vector<Street_cluster_spawn> streets_to_spawn;
    streets_to_spawn.push_back(straight_street_spawn);
    streets_to_spawn.push_back(crossed_street_spawn);
    streets_to_spawn.push_back(to_left_street_spawn);
    streets_to_spawn.push_back(to_right_street_spawn);
    streets_to_spawn.push_back(t_shaped_street_spawn);


    //Testing bildings

    static Parameters_for_building house_parameters = Parameters_for_building("house_part", 25, Colour(55, 55, 55), Colour(55, 55, 55));
    static Parameters_for_building station_parameters = Parameters_for_building("station_part", 50, Colour(148, 255, 234), Colour(148, 255, 234));
    static Parameters_for_building police_station_parameters = Parameters_for_building("police_station_part", 150, Colour(108, 63, 204), Colour(108, 63, 204));
    static Parameters_for_building hospital_parameters = Parameters_for_building("hospital_part", 200, Colour(232, 90, 90), Colour(232, 90, 90));

    //House building
    static vector<Building_component> house_building_components;

    house_building_components.push_back(Building_component(&house_parameters, Position(0, 0, 0)));

                    //house_building_components.size() * house_parameters.get_cost()

    static Building_cluster house_building = Building_cluster(house_building_components, house_building_components.size() * house_parameters.get_cost(), 5.95);
    static Building_cluster_spawn house_building_spawn = Building_cluster_spawn(&house_building, 5.95);

    //Station building
    static vector<Building_component> station_building_components;

    station_building_components.push_back(Building_component(&station_parameters, Position(0, 0, 0)));
    station_building_components.push_back(Building_component(&station_parameters, Position(1, 0, 0)));

    static Building_cluster station_building = Building_cluster(station_building_components, 50, 0.2);
    static Building_cluster_spawn station_building_spawn = Building_cluster_spawn(&station_building, 0.2);

    //Police station building
    static vector<Building_component> police_station_building_components;

    police_station_building_components.push_back(Building_component(&police_station_parameters, Position(0, 0, 0)));
    police_station_building_components.push_back(Building_component(&police_station_parameters, Position(1, 0, 0)));
    police_station_building_components.push_back(Building_component(&police_station_parameters, Position(1, 1, 0)));

    static Building_cluster police_station_building = Building_cluster(police_station_building_components, police_station_building_components.size() * police_station_parameters.get_cost(), 0.05);
    static Building_cluster_spawn police_station_building_spawn = Building_cluster_spawn(&police_station_building, 0.15);

    //Hospital building
    static vector<Building_component> hospital_building_components;

    hospital_building_components.push_back(Building_component(&hospital_parameters, Position(0, 0, 0)));
    hospital_building_components.push_back(Building_component(&hospital_parameters, Position(1, 0, 0)));
    hospital_building_components.push_back(Building_component(&hospital_parameters, Position(1, 1, 0)));
    hospital_building_components.push_back(Building_component(&hospital_parameters, Position(2, 1, 0)));

    static Building_cluster hospital_building = Building_cluster(hospital_building_components, hospital_building_components.size() * hospital_parameters.get_cost(), 0.02);
    static Building_cluster_spawn hospital_building_spawn = Building_cluster_spawn(&hospital_building, 0.15);

    vector<Building_cluster> buildings;

    /*buildings.push_back(house_building);
    buildings.push_back(station_building);*/

    vector<Building_cluster_spawn> buildings_to_spawn;
    buildings_to_spawn.push_back(house_building_spawn);
    buildings_to_spawn.push_back(station_building_spawn);
    buildings_to_spawn.push_back(police_station_building_spawn);
    buildings_to_spawn.push_back(hospital_building_spawn);

    //Testing clutters

    static Parameters_for_clutter wheat_field_parameters = Parameters_for_clutter("wheat_field_clutter_part", Type_of_clutter::Specific, true, true, true, 50, Colour(255, 202, 24), Colour(255, 202, 24));

    //Wheat field clutter
    static vector<Clutter_component> wheat_field_clutter_components;

    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(0, 0, 0)));
    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(1, 0, 0)));
    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(2, 0, 0)));
    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(0, 1, 0)));
    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(1, 1, 0)));
    //wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(2, 1, 0)));

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            wheat_field_clutter_components.push_back(Clutter_component(&wheat_field_parameters, Position(i, j, 0)));
        }
    }

    static Clutter_cluster wheat_field_clutter = Clutter_cluster(wheat_field_clutter_components, 0.8);

    static Clutter_cluster_spawn wheat_field_clutter_spawn = Clutter_cluster_spawn(&wheat_field_clutter, 0.8);

    vector<Clutter_cluster_spawn> clutters_to_spawn;

    clutters_to_spawn.push_back(wheat_field_clutter_spawn);

    new_map.set_clutters_probability_to_spawn(clutters_to_spawn);

    //static Parameters_for_city parameters_for_city = Parameters_for_city("Mala Tokmachka", Size_dimensional(100, 100, 20), Size_dimensional(400, 400, 200));
    //static City city = City(buildings, buildings_to_spawn, streets_to_spawn, parameters_for_city, 0, Position(500, 500, 0));
    
    // TEST
    for (int i = 0; i < 14; i++) {
        string name = "City " + i;
        Parameters_for_city parameters_for_city = Parameters_for_city(name);
        auto city = std::make_unique<City>(buildings, buildings_to_spawn, streets_to_spawn, parameters_for_city);
        city->create_city(new_map);
        new_map.add_city(std::move(city));
    }
    /*static Parameters_for_city parameters_for_city = Parameters_for_city("Mala Tokmachka");
    static City city = City(buildings, buildings_to_spawn, streets_to_spawn, parameters_for_city);

    city.create_city(new_map);*/

    for (int i = 0; i < 14; i++) {
        std::cout << "City " << i << ": " << std::endl;
        for (int j = 0; j < new_map.get_cities()[i]->end_of_streets.size(); j++) {
            std::cout << "end of street: pos x: " << new_map.get_cities()[i]->end_of_streets[j].get_on_x() <<
                ": pos y: " << new_map.get_cities()[i]->end_of_streets[j].get_on_y() <<
                ": pos z: " << new_map.get_cities()[i]->end_of_streets[j].get_on_z() << std::endl;
        }
        std::cout << "end of street size: " << new_map.get_cities()[i]->end_of_streets.size() << std::endl;
    }
    new_map.create_clutters(100);

    //for (int i = 0; i < 14; i++) {
    //    std::cout << "Center of City " << i << ": pos x: " << new_map.get_cities()[i]->get_center_of_city().get_on_x() <<
    //        ": pos y: " << new_map.get_cities()[i]->get_center_of_city().get_on_y() <<
    //        ": pos z: " << new_map.get_cities()[i]->get_center_of_city().get_on_z()<< std::endl;
    //}

    new_map.render_map();

    return 0;
}