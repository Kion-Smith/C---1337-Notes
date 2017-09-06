#include <iostream>
#include <fstream>

using namespace std;



void copyNumbers();

int main()
{
    try
    {





    }
    catch(exception e)
    {

        cout<<"An error";
    }




    return 0;
}


void copyNumbers()
{
    inputFileStream.open("inputFile.txt", ios::in);
    outputFileStream.open("outputFile.txt", ios::out);

    if(inputaafileStream)
    {

        cout<<"Input file opened succesfully"<<endl;

    }
    else
    {
        cout <<"ERROR"<<endl;
    }

}
