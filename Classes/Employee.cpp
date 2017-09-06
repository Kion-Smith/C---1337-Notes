#include <Employee.h>

Employee::Employee()
{
    cout<<"default"<<endl;
    empNumber =0;
    name="";
    hours= 0;
    payrate=0;
    address ="";

    int defaultSize=50;
    address = new char[defaultSize+1];

}
Employee::Employee(int empNum,string InputName,char* empAddress,double hourlyRate,double hoursWorked =0.0)
{
    cout<<"EXPLICIT"<<endl;
    empNumber=empNum;
    name=InputName;
    hours=hoursWorked;
    payrate=hourlyRate;
    address = empAddress;

    //Dynamic mem
    address = new char[strlen(empAddress)+1];
    strcpy(address,empAddress);

}
Employee::Employee(int empNumber,string inputName)
{
    cout<<"2 name constructor"<<endl;
    empNumber=empNumber;
    name=inputName;
    hours=0;
    payrate=0;
    address ="";

    int defaultSize=50;
    address = new char[defaultSize+1];

}



Employee::~Employee()
{
    cout<<"Debug:Destructor invoked"<<endl;
    delete [] address;
    address = nullptr;

}


void Employee::setName(string inputName)
{
    name = inputName;
}
void Employee::setName(char* inputcharn)
{
    name =inputcharn;
}
string Employee::getName() const
{
    return name;
}

void Employee::setEmpInfo(int empNum,string InputName,double hourlyRate,double hoursWorked =0.0)
{
    empNumber = empNum;
    name = InputName;
    hours = hoursWorked;
    payrate = hourlyRate;
}
void Employee::displayInfo()
{
    cout<<"Employee:: "<<name<<endl;
    cout<<"has a number of::"<<empNumber<<endl;
    cout<<" has worked for:: "<<hours<<endl;
    cout<<" at an hourly rate:: "<<payrate<<endl;
   // cout<<"And there address is:: "<<address<<endl;
   // cout<<" ,Current grosspay is $"<< getGrosspay();
}


double Employee::getGrosspay() const
{

}

void Employee::calcGrossPay()
{
    hours * payrate;
}

