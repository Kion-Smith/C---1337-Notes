//
//  Employee.cpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/2/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#include "Employee.hpp"


//
Employee::Employee() {
    cout << "DEBUG: Employee Default constructor invoked." << endl;
    empNumber = 0;
    name = "Default Name";
    hours = 0.00;
    payRate = 0.00;

    //string contactAddress;
    //string mailinAddress;

    //dynamic memory allocation
    int defaultAddressLength = 50;
    address = new char[defaultAddressLength + 1];
}
//

Employee::Employee(int empNum, string empName){
    cout << "DEBUG: Employee Two-arg constructor invoked." << endl;
    empNumber = empNum;
    name = empName;
    hours = 0.00;
    payRate = 0.00;

    //dynamic memory allocation
    int defaultAddressLength = 50;
    address = new char[defaultAddressLength + 1];
}

Employee::Employee (int empNum, string empName, char * empAddress, double hourlyRate, double hoursWorked = 0.0) {
    cout << "DEBUG: Explicit constructor invoked." << endl;
    empNumber = empNum;
    name = empName;
    hours = hoursWorked;
    payRate = hourlyRate;

    address = empAddress;

    //dynamic memory allocation
    address = new char[strlen(empAddress)+1];
    strcpy(address, empAddress);
}

Employee::~Employee() {
    cout << "DEBUG: Destructor invoked for Emp-ID: " << empNumber << endl;

    //release dynamic memory allocated
    //delete [] address;
    //address = nullptr;
}

void Employee::setName(string inputName) {
    name = inputName;
}

void Employee::setName(char* inputCharArray) {
    name = inputCharArray;
}


void Employee::setEmpNumber(int empNo) {
    empNumber = empNo;
}
string Employee::getName() const{
    return name;
}

/*
 void Employee::setEmployeeInfo(int empNum, double hourlyRate, double hoursWorked = 0.0) {
 empNumber = empNum;
 hours = hoursWorked;
 payRate = hourlyRate;
 }
 */
void Employee::displayInfo() {
    cout << "Employee Name: " << name << ", (ID: " << empNumber << ")" << endl;
    //cout << " has worked for " << hours << " hours.";
    //cout << " At an hourly rate of $" << payRate;
    //cout << ", current grossPay is $" << getGrossPay() << endl;
}


const Employee Employee::operator=(const Employee &emp) {
    cout << "Debug: operator overload function called" << endl;
    //use this pointer to refer to current object (ie the obj on the left hand side of of =)
    this->empNumber = emp.empNumber;
    this->name = emp.name;
    this->payRate  = emp.payRate;
    this->hours = emp.hours;
    //...

    return *this;
}

Employee::operator string() {
    return this->name;
}
