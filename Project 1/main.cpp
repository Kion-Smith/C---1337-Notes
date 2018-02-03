#include <iostream>
#include <iomanip>
#include "main.h"
//Author: Kion Smith
using namespace std;

void userInputs();
void calcFunctions(string,int,float);

int main()
{
    try
    {
        userInputs();


    }
    catch(exception e)
    {
        cout << "An error has occurred"<< endl;
        return -1;
    }



    return 0;
}

void userInputs()
{
    string userMonth;
    int userYear;
    float userMoney;

    cout <<"What month do you want to input::"<<endl;

        cin >> userMonth;

    cout <<"What year do you want to input::"<<endl;

        cin >> userYear;

    cout <<"Enter the amount of money do you want to input::"<<endl;

        cin >> userMoney;

   // cout << userMonth <<" "<< userYear<< " "<< (float)(userMoney) << endl;

    calcFunctions(userMonth,userYear,userMoney);

}
void calcFunctions(string month,int year,float money)
{

    float calcStateTax;
    float calcCountyTax;
    float TotalSalesTax;
    float TotalSales;

    string answer;
    string y = "y";
    string Y = "Y";

    calcStateTax = (float)(.065 * money);
    calcCountyTax = (float)(.0275 * money);

    TotalSalesTax = (float)(calcCountyTax+calcStateTax);

    TotalSales = (float)(TotalSalesTax+money);

    cout<<endl;
    cout<<month<<" "<<year<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Total Collected:: "<< setprecision(2)<<fixed<<TotalSales <<endl;
    cout<<"Sales:: "<< setprecision(2)<<fixed<<money <<endl;
    cout<<"County Sales Tax:: "<< setprecision(2)<<fixed<<calcCountyTax <<endl;
    cout<<"State Sales Tax:: "<< setprecision(2)<<fixed<<calcStateTax <<endl;
    cout<<"Total Sales Tax:: "<< setprecision(2)<<fixed<<TotalSalesTax <<endl;

    cout<<endl;
    cout<<"Would you like to perform another calculation(Y/N)"<<endl;
    cin >> answer;

    if(answer.compare(y) == 0||answer.compare(Y) == 0)
    {

        userInputs();
    }
    else
    {

    }




}
