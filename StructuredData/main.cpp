#include <iostream>

using namespace std;

struct Employee
{
   int eNum;
   string eName;
   double eHours,ePayRate,eGrossPay;



};

int main()
{

    Employee employee;
    /*

    cout <<"What is your number?"<<endl;
    cin>> employee.eNum;

    cout<<"What is your name?"<<endl;
    cin>>employee.eName;

    cout<<"What are the hours you worked?"<<endl;
    cin>>employee.eHours;

    cout<<"What us your pay rate?"<<endl;
    cin>>employee.ePayRate;

    employee.eGrossPay = employee.eHours * employee.ePayRate;

    cout<<"Number is :: " << employee.eNum<<endl;
    cout<<"Name is :: " << employee.eName<<endl;
    cout<<"Hours:: " << employee.eHours<<endl;
    cout<<"Payrate :: " << employee.ePayRate<<endl;
    cout<<"Gross pay:: " << employee.eGrossPay<<endl;


*/



    // Create Instance of a struct

    Employee emp1;
     emp1.eNum = 102;
     emp1.eName = "Sue Bass";

     Employee emp2 = {101,"Joe Parker",40.0,25.50,0.00};
     Employee emp3 = {103, "Smith Parker",19.0,17.50};// You can skip certain variables
     Employee emp4 = {104,"Smith Williams"};



     Employee emp5 = emp3;
     cout<< "emp5 name is ::"<< emp5.eName<<endl;




     //Comparing Struct "Objects"
     /*

     CANT DO THIS YOU MUST COMPARE ON A SIMPLE LEVEL
     if(emp2 == emp4)
     {

     }
    */

    if(emp2.eNum == emp4.eNum)
    {
        cout<<"They are the same number"<<endl;
    }

    //cout << emp2 <----- Creates a compile time
    cout<< emp2.eNum<<endl;

    // Array of Structs objects
    //int myIntList[10]; <-- Calling a regular array
    Employee myEmpList[5];// an array of 5 employee struct objects

    for(int i = 0;i<5;i++)
    {

        myEmpList[i].eNum = 100 + i;// You cant just use the dot opperator you also need the [i]
        cout<< "Employee "<< i+1<< " has a number of "<< myEmpList[i].eNum<<endl;
    }

    // On ELearing there are more complex structs things to look at



    return 0;
}
