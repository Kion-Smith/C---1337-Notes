/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/
#ifndef info_hpp
#define info_hpp


#include <iostream>
#include<fstream>
#include<string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>

#include "Planets.hpp"
#include "Shuttles.hpp"

using namespace std;

ofstream outputFile ("Delivery_Report.txt");//output file

//All the various function calls to store information into shuttles class
void cargoType();//gets cargo name
void pickupPlanet();//gets 1st planet
void DPlanet();//gets other planet
void Weight();//gets weight
void speed();//gets speed

//All the various function calls the do calculations for it's variables
void calcTotalDist();//calculates the distance between planets
void calcEarthWeight();//calculates the object weight on earth
void calcWeightOtherP();//calculates the object weight on other planets
void calcTime();//gets the time
void runP();//main caller,handles all the functions
void reRun();//used to run the program a second time
void writeToFile();//Write to the out put function

void createPlanets();//Used to create the area of Planets

Planets listOfPlanets[8];//Array of Planet objects

//All Local variables used by the project
double earthWeight;//earths weight
double otherPlanet;//the other planets weight
double hourT;//Time in hours
double dayT;//time in days
double yearT;//time in years
double distanceToP;//distance between planets


Shuttles userShut;// Shuttle object

#endif
