/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/
#ifndef Planets_hpp
#define Planets_hpp


#include <iostream>
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class Planets
{


private:
    string name;// name of planet
    int dSun;// distance from the sun
    double SGfactor;//surface gravity factor



public:
    Planets();
    Planets(string,int,double);
   ~Planets();//destructor

    //getter
   void setName(string);
   void setDistFromSun(int);
   void setSurfaceGravFactor(double);
    //setters
   string getName();
   int getDistFromSun();
   double getSurfaceGravFactor();

};
#endif
