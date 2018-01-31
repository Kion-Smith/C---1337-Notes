/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/
#include "Shuttles.hpp"

Shuttles::Shuttles()//default constructor
{
    cargoTypeName ="";
    startPlanet=0;
    endPlanet=0;
    weight=0.0;
}

//setters
    void Shuttles::setCargoType(string cgt)
    {
      cargoTypeName = cgt;
    }
    void Shuttles::setStartPlanet(int sp)
    {
        startPlanet = sp;
    }
    void Shuttles::setEndPlanet(int ep)
    {
        endPlanet = ep;
    }
    void Shuttles::setWeight(double wo)
    {
        weight = wo;
    }
    void Shuttles::setSpeed(int s)
    {
        speed = s;
    }

    /////////////Getters
    string Shuttles::getCargoType()
    {
        return cargoTypeName;
    }
    int Shuttles::getStartPlanet()
    {
        return startPlanet;
    }
    int Shuttles::getEndPlanet()
    {
        return endPlanet;
    }
    int Shuttles::getWeight()
    {
        return weight;
    }
    int Shuttles::getSpeed()
    {
        return speed;
    }




Shuttles::~Shuttles()
{

}
