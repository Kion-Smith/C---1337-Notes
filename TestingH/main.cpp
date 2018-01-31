//
//  InheritanceDemo.cpp
//  Section503Demo
//
//  Created by Ebenezer Oladimeji on 11/28/16.
//  Copyright © 2016 Ebenezer Oladimeji. All rights reserved.
//

#include "InheritanceDemo.hpp"
#include "Faculty.hpp"
#include "Employee.hpp"

void displayUserInfo(Employee &empObj);

int main() {
    try {
        Faculty fac1;
        fac1.setEmpNumber(901);
        fac1.setName("Mellie Fitz");
        //fac1.Employee::displayInfo();

        Faculty fac2(101, "Dr. O.", "Comp. Sc.", "Associate Prof.", true);
        displayUserInfo(fac2);

        Employee emp3(202, "Carlos Miranda");
        displayUserInfo(emp3);

    } catch (...) {
        cout << "An error has occurred while executing the program. \n\n";
        return -1;
    }
    //all local vars in the try block are now out of scope (implicit call to destructor)
    //cout << "Debug pt3: Currenly logged-on users: " << MyApp::getUserCount() << endl;

    cout << "Program about to terminate..." << endl;

    return 0;
}

void displayUserInfo(Employee &empObj) {
    cout << "DEBUG: Generic displayUserInfo: " << endl;
    empObj.displayInfo();

}
