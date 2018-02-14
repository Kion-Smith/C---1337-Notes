#include "ClassesDemo.hpp"
#include "Employee.hpp"
#include "MyApp.hpp"

//#include "Budget.hpp"

int main() {
    try {


        Employee emp;       //implicitly invokes the default constructor
        emp.setName("John Smith");

        cout << "Employee Name is: " << emp.getName() <<endl;

        //emp.calculateGrossPay();  //attempt to access a protected member; compiler error!

        //Using pointers to ADT (objects)
        int *intPtr  = nullptr;
        Employee *empPtr = &emp;
        cout << "Pointer::Employee Name: " << (*empPtr).getName() << endl;
        cout << "Short-Hand:Pointer::Employee Name: " << empPtr->getName() << endl;

        empPtr->displayInfo();

        //release dynamic memory
        //delete empPtr;       //mark this memory location as available for garbage collection
        //empPtr = nullptr;    //disconnect the pointer variable from the mem loc.

        Employee emp2(201, "Mary McKaine", "May Address", 34.55, 40.0);
        emp2.displayInfo();

        //Destructor: main purpose: release resources held by the obj (e.g. dyn mem alloc)
        Employee *empPtr2;
        char * empAddress = (char *)"Marys Address";
        empPtr2 = new Employee(201, "Mary McKaine", empAddress, 34.55, 40);
        empPtr2->displayInfo();

        delete empPtr2;     //implicitly invoke the destructor
        empPtr2 = nullptr;

         //member function/constructor overloading
        Employee emp3(601, "John Smith");       //implicitly invokes the default constructor
        //emp3.displayInfo();
        string nameStr = "Marco Ruchir";
        emp3.setName(nameStr);
        //emp3.displayInfo();
        char * nameCharArray = "Dude Dudupudi";
        emp3.setName(nameCharArray);
        //emp3.displayInfo();

        //arrays of ADTs
        Employee empList[3] = {
            Employee(601, "Mark Carpenter"),
           Employee(701, "Joe Plumber"),
            Employee(801, "Mary Magdalene", "Marys Address", 37, 23.99)
        };
        for (int index = 0; index < 3; index++) {
            empList[index].displayInfo();
        }

        //static member variables and functions
        MyApp appInst1("john.doe", "password123");
        cout << "Debug pt1: Currenly logged-on users: " << appInst1.getUserCount() << endl;
        MyApp appInst2("mary.smith", "password124");
        cout << "Debug pt2: Currenly logged-on users: " << MyApp::getUserCount() << endl;


        //overloading operator =
        Employee emply1(801, "Joe Plumber", "Joe Address", 37, 23.99);
        Employee emply2;
        Employee emply3;

        //emp2 = emp1;  //simple case
        emply3 = emply2 = emply1;   //recursive case
        emply3.displayInfo();

        //overload the < operator on Employee class
        Employee emp4(801, "Joe Plumber", "Joe Address", 37, 23.99);
        Employee emp5(901, "Tony Romo", "Tony Address", 25.99, 17.00);

        if (emp4 < emp5) {
            cout << "Employee " << emp4.getName() << " is the junior" << endl;
        } else {
            cout << "Employee " << emp4.getName() << " is the boss!" << endl;
        }

        //conversion to string (aka toString())
        Employee emp6(801, "Joe Plumber", "Joe Address", 37, 23.99);
        cout << "Employee in string form is: " << (string)emp6 << endl;

    } catch (...) {
        cout << "An error has occurred while executing the program. \n\n";
        return -1;
    }
    //all local vars in the try block are now out of scope (implicit call to destructor)
    //cout << "Debug pt3: Currenly logged-on users: " << MyApp::getUserCount() << endl;

    cout << "Program about to terminate..." << endl;

    return 0;
}
