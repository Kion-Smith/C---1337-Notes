//==========
//
//  Address.hpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/16/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#ifndef Address_hpp
#define Address_hpp

#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string houseNumber;
    string streetName;
    string city;
    string state;
    string zipCode;

public:
    string getFullAddress();
};
#endif /* Address_hpp */
