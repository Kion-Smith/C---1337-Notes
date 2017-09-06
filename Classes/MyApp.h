#ifndef MYAPP_H_INCLUDED
#define MYAPP_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class MyApp
{
    private:
        static int userCount;
        bool authenticate(string,string);

    public:
        MyApp(string, string);
        ~MyApp();
       // static int getUserCount() const; Static member can have const
       static int getUserCount();

};
static int userCount=0;

#endif // MYAPP_H_INCLUDED
