#include <iostream>


using namespace std;

int main()
{



    float farhen = 0.0;
    float celcius =0.0;

try{
    cout  << "Enter a number to covert to celcius::" << endl;

    cin >> farhen;// user input;

        celcius = (farhen-32)*5/9;

        int numberofRuns=0;




   cout <<"The temp old temp was "<< farhen << " the new one is "<< celcius <<" in celcius"<< endl;
   if(celcius >= 35.0)
   {
       cout << "It's hot outside!"<< endl;
       main();
   }

   else if(celcius <=15)
   {
       cout <<"It's cold outside"<<endl;
       main();
   }
   else
    {
     cout<<"It's normal weather"<< endl;
    main();
   }
}
catch(exception exceptionObject)
{

    return -1;
}



    return 0;
}
