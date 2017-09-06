#include <MyApp.h>

MyApp::MyApp(string userName, string password)
{
    if(authenticate(userName,password))
    {
        userCount++;
    }
}

MyApp::~MyApp()
{
    userCount = (userCount>0)? userCount++ : userCount;  //teneroperator
    /* SAME THING AS THIS!//////
    if(userCout>0)
        userCount--;
    */
}

bool MyApp::authenticate(string userId,string pswd )
{
    return true;
}

int MyApp::getUserCount()
{
    return userCount;
}
