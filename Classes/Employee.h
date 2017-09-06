#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Employee
{
    private:
       int empNumber;
       string name;
       char *address;
       double hours,payrate;



    protected:
        void calcGrossPay();

    public:
        Employee();//default
       // Employee(int empNumber-0);
        Employee(int empNumber,string);
        Employee(int empNum,string,char*,double,double);//explicit constructor

        ~Employee();//deconstructer only 1 per class

        void setName(string);
        void setName(char*);//mutator

        string getName() const;

          void setEmpNum(int);
        int getEmpName() const;

        void setEmpInfo(int,string,double,double);
        void displayInfo();

          void setHRate(double hourlyRate);
        double getHRate() const {return payrate;} //IN line implementation of a function



        double getGrosspay() const;

};


#endif // EMPLOYEE_H_INCLUDED
