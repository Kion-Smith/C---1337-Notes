#include <iostream>
#include <Employee.h>
#include <MyApp.h>

using namespace std;

int main()
{   /*
    Employee emp;

    emp.setName("John Smith");
    cout<<"Employees name::"<< emp.getName()<<endl;

    int* intPtr=nullptr;
    //Employee *empPtr=nullptr;
    Employee *empPtr =&emp;

    cout<<(*empPtr).getName()<<endl;
    cout<< empPtr ->getName()<<endl;

    empPtr->displayInfo();

    //deleting the pointer

    delete empPtr;//marked for garbage collection
    empPtr= nullptr;//disconnect pointer from memory location

    //Employee emp2 (201,"Pepe the Frog",34.55,40);
   // emp2.displayInfo();

   //Destructor - release resources held by an object(dynamic memory)
*/
/*
   Employee *empPtr2;
   char* empAddress = (char*)"Meme address";
   empPtr2 = new Employee(201,"Pepe the Frog","Meme address",34.55,40);
   empPtr2->displayInfo();
   delete empPtr2;//Implict invoke the destructor
   empPtr2 = nullptr;

   Employee emp3(301,"John Smith");
   string nameStr="Mrck";
   emp3.setName(nameStr);
   emp3.displayInfo();

    char * nameStr1="oh no";
   emp3.setName(nameStr1);
   emp3.displayInfo();


//Member functions/constructor overloading



    //array of ADTS
    Employee emp3(601,"John Smith");

    Employee empList[3] = { emp3,Employee(701,"FeelsGuy"),Employee(801,"Pepe","House of memes",37,23.99)};

    for(int i=0;i<3;i++)
    {
        empList[i].displayInfo();
    }
*/

//DAY 3/**<  */
MyApp appInst("john.doe","password123");
cout<<"Debug pt1: Currently Loggged on users"<<appInst.getUserCount()<<endl;
MyApp appInst2("Mary.smith","password124");
cout<<"Debug pt2: Currently Loggged on users"<< MyApp::getUserCount()<<endl; // same as Math::pow or std::
//Not working overloading and overiden check later, mines not working :(

    return 0;
}
