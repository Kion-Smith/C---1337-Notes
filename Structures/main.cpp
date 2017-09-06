#include <iostream>
#include <iomanip>

using namespace std;

struct  Employee
{
    int empNum;
    string empName;
    double hours,payRate,grossPay;



};

void displayInfo(Employee);
void calcGrossPay(Employee &);
void showInfo(const Employee &);
Employee captureEmployeeInfo();
//void populationEmployeeInfo(Employee *);

int main()
{
    try
    {

        Employee emp5 = {101,"Joe Parker",40.0,25.0};


        //Structs as a function argument
        //Passing it by value (1)
        displayInfo(emp5);

        //passing by reference (2)
        calcGrossPay(emp5);
        displayInfo(emp5);

        //passing by constant reference (3)
        showInfo(emp5);

        //Return a struct function
        Employee emp6 = captureEmployeeInfo();
        showInfo(emp6);


        //Pointers to structs

        //Employee *emp7Ptr = nullptr;
        //populateEmpoyeeInfo(emp7);
        //Can't Do this right now I cant use nullptr its not in this version of c++

    }
    catch(exception e)
    {

        cout<<"There was an error"<<endl;
        return -1;
    }

    return 0;
}
void displayInfo(Employee emp)
{
    cout<< fixed<< showpoint << setprecision(2);
    cout<<"Employees name is :: "<< emp.empName <<endl;
    cout<<"Employee number is :: "<< emp.empNum<<endl;
    cout<< "Hours worked till Date:: "<< emp.hours<< " hours at $"<<emp.payRate<<endl;
    cout<<" Employee Gross Pay:: $"<< emp.grossPay<<endl<<endl;
}

void calcGrossPay(Employee &emp)
{

    emp.grossPay = emp.hours * emp.payRate;

}

void showInfo(const Employee &emp)
{
    cout<< fixed<< showpoint << setprecision(2);
    cout<<"Employees name is :: "<< emp.empName <<endl;
    cout<<"Employee number is :: "<< emp.empNum<<endl;
    cout<< "Hours worked till Date:: "<< emp.hours<< " hours at $"<<emp.payRate<<endl;
    cout<<" Employee Gross Pay:: $"<< emp.grossPay<<endl<<endl;

}
Employee captureEmployeeInfo()
{
    Employee tempEmp;
    cout <<"What is your number?"<<endl;
    cin>> tempEmp.empNum;

    cout<<"What is your name?"<<endl;
    cin>>tempEmp.empName;

    cout<<"What are the hours you worked?"<<endl;
    cin>>tempEmp.hours;

    cout<<"What us your pay rate?"<<endl;
    cin>> tempEmp.payRate;

    calcGrossPay(tempEmp);

    return tempEmp;
}


/*
void populationEmployeeInfo(Employee *empPtr)
{
    empPtr = new Employee;

    Employee tempEmp;
    cout <<"What is your number?"<<endl;
    cin>> (*empPtr).empNum;

    cout<<"What is your name?"<<endl;
    cin>>empPtr->empName;

    cout<<"What are the hours you worked?"<<endl;
    cin>>empPtr->hours;

    cout<<"What us your pay rate?"<<endl;
    cin>>empPtr->payRate<<endl;

    calcGrossPay(*empPtr);//* allows us to actually use the object

    return tempEmp;
}



}

*/
