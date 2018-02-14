//  MyApp.cpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/14/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#include "MyApp.hpp"

MyApp::MyApp(string userName, string password) {
    if (authenticate(userName, password)) {
        //increment static user count
        //MyApp::userCount++;
    }
}

MyApp::~MyApp() {
    //MyApp::userCount = (MyApp::userCount > 0)? MyApp::userCount-- : MyApp::userCount;
    //if (userCount > 0) {  //above ternary operator equivalent to this if statement
    //    userCount--;
    //}
}

bool MyApp::authenticate(string userId, string pswd) {
    //assume user authenticates successfuly
    return true;
}

int MyApp::getUserCount() {
    return 0; //MyApp::userCount;
}
