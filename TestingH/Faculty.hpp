//=======
//
//  Faculty.hpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/28/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#ifndef Faculty_hpp
#define Faculty_hpp

#include <iostream>
#include <string>
#include "Employee.hpp"

using namespace std;

class Faculty : public Employee {
private:
    string department;
    string rank;
    bool isTenured;

public:
    Faculty();  //default constructor
    Faculty(int id, string name, string dept, string rank, bool tenured);

    ~Faculty();  //destructor

    void displayInfo();   //Redefinition or Overriding

};

#endif /* Faculty_hpp */
