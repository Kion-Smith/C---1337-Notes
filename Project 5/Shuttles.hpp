/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/
#ifndef Shuttles_hpp
#define Shuttles_hpp


#include <iostream>
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class Shuttles
{
private:
     string cargoTypeName;
     int startPlanet;
     int endPlanet;
     double weight;
     int speed;



public:
    Shuttles();

    void setCargoType(string);
    void setStartPlanet(int);
    void setEndPlanet(int);
    void setWeight(double);
    void setSpeed(int);

    string getCargoType();
    int getStartPlanet();
    int getEndPlanet();
    int getWeight();
    int getSpeed();


   ~Shuttles();

};

#endif
