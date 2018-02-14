//
//  MyApp.hpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/14/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#ifndef MyApp_hpp
#define MyApp_hpp

#include <iostream>
#include <string>

using namespace std;

class MyApp {
private:
    static int userCount;   //static member attribute declaration
    bool authenticate(string, string);


public:
    MyApp(string, string);
    ~MyApp();    //destructor

    //provide access to static variables via static functions
    static int getUserCount();
};

//static member variables must be defined outside of the class decl.
static int userCount = 0;   //static member attribute definition

#endif /* MyApp_hpp */
