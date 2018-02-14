//==========
//
//  Address.cpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/16/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#include "Address.hpp"

string Address::getFullAddress() {
    return this->houseNumber + " " +
    this->streetName + ", " +
    this->city + " " +
    this->state + " " +
    this->zipCode ;

}
