//==========
//
//  Faculty.cpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/28/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#include "Faculty.hpp"

Faculty::Faculty() : Employee() //default constructor
{
    cout << "Default Faculty constructor invoked" << endl;
}

//main constructor
Faculty::Faculty(int id, string name, string dept, string rank, bool tenured) :
Employee(id, name)
{
    cout << "Main Faculty constructor invoked" << endl;
    this->department = dept;
    this->rank = rank;
    this->isTenured = tenured;
}

//destructor
Faculty::~Faculty() {
    cout << "DEBUG: Faculty Destructor invoked for Emp-ID: " << empNumber << endl;

}
void Faculty::displayInfo() {
    cout << "Faculty Name: " << getName() << "(ID: " << empNumber;
    cout << "), Rank: " << rank << ", and isTenured: " << isTenured << endl;
}
