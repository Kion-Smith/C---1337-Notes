//
//  Employee.hpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/2/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
#include <string>
#include "Address.hpp"
#include <string.h>

using namespace std;

class Employee {
private:
    string name;
    char * address;
    double hours;
    double payRate;

    Address mailingAddress;
    Address contactAddress;


protected:
    void calculateGrossPay();
    int empNumber;

public:
    Employee();             //default constructor
    Employee(int empNum, string);
    Employee(int empNum, string, char *, double, double);  //explicit constructor

    ~Employee();    //destructor: only one is allowed per class

    void setName(string);         //mutator member function
    void setName(char *);         //mutator member function

    string getName() const;

    void setEmpNumber(int);
    int getEmpNumber() const;

    void setHourlyRate(double hourlyRate);
    double getHourlyRate() const{ return payRate; }   //inline implementation of a function

    void setEmployeeInfo(int, string, double, double);

    double getGrossPay() const { return hours * payRate; }

    //void displayInfo();
    virtual void displayInfo();


    //overloaded operators
    const Employee operator=(const Employee &);
    //const Employee operator=(const Person &);

    bool operator<(const Employee &emp) {
        return (this->payRate < emp.payRate);
    }

    //conversion operator toString
    operator string();
};

#endif /* Employee_hpp */
