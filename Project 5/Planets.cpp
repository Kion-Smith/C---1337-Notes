/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/

#include "Planets.hpp"


Planets::Planets()//default constructor
{
    name = "default";
    dSun = 0;
    SGfactor = 0.0;

}
Planets::Planets(string n,int ds,double sgf)//another constructor and the one used in the main project
{
    name = n;
    dSun = ds;
    SGfactor = sgf;
}

//setters
   void Planets::setName(string n)
   {
       name = n;
   }
   void Planets::setDistFromSun(int ds)
   {
       dSun = ds;
   }
   void Planets::setSurfaceGravFactor(double sgf)
   {
       SGfactor = sgf;
   }
//getter in case I need to quick access
   string Planets::getName()
   {
       return name;
   }
   int Planets::getDistFromSun()
   {
       return dSun;
   }
    double Planets::getSurfaceGravFactor()
   {
       return SGfactor;
   }

    Planets::~Planets()
    {
    }
