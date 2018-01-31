/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 5
*/
#include "info.hpp"

int main()
{
    try
    {
        createPlanets();//Make the area of planets
        runP();


    }
    catch(exception e)
    {
        cout<<"An error has occurred"<<endl;
        return -1;
    }
    return 0;
}

void runP()
{
        cargoType();

        calcTotalDist();
        calcWeightOtherP();
        calcTime();
        writeToFile();

        reRun();

}
void reRun()
{
    //I have to use re run, when using the cin,fail method of checking for validation
        int userInput;
        cout<<"Do you want to run the program again?"<<endl;
        cout<<"0) Yes"<<endl;
        cout<<"1) No"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        cin>>userInput;

          if(cin.fail())
            {
            cin.clear();
            cin.sync();

            cout<<"Sorry, the input you gave was not a number, please enter a number"<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;

            reRun();

            }
            else if(userInput<0 || userInput>1)
            {
            cout<<"Sorry, the input you gave was not within the answer choices range"<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;

            reRun();
            }
            else if(userInput == 0)
            {
                runP();
            }
            else
            {
                cout<<"Exiting program"<<endl;
            }
}


void createPlanets()
{

    int i =0;


     string tempString1 ="";//used to split the string into data to use
     string tempString2 ="";
     string tempString3 ="";

     int tempInt =0;
     double tempDoub =0;

     string PlanetLine;

    ifstream pFile("Planet_Info.txt");//read the file


        while(getline(pFile,PlanetLine))
        {

             tempString1 = PlanetLine.substr(0,PlanetLine.find(" ")+1);//First item is easily done by going from index to the first space

            tempString2 = PlanetLine.substr(PlanetLine.find(" ")+1);//2nd is more complecated;Split the sentence into from were tempstring1 left off
            tempString3 = tempString2.substr(tempString2.find(" ")+1,tempString2.length()-1);// from the first space to the end get the information
            tempString2 = tempString2.substr(0,tempString2.find(" ")+1);// then finally split the start of the string

            //stoi did not want to work, so alternative of string streaming
            stringstream convert(tempString2);
            convert>>tempInt;

            stringstream convert1(tempString3);
            convert1>>tempDoub;

            listOfPlanets[i] = Planets(tempString1,tempInt,tempDoub);//create the planets at that index

             i++;
        }
}

void cargoType()
{

    string userInput ="";

    cout<<"Enter what type of cargo are you transporting?"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>userInput;

     if(cin.fail())
    {
        cin.clear();
        cin.sync();

        cout<<"Sorry, the input you gave was not a string, please enter a string"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        cargoType();

    }
    else
    {
        //store string go to the next method
        userShut.setCargoType(userInput);
        pickupPlanet();//move to the next method

    }
}
void pickupPlanet()
{
    int userInput;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"0) Mercury"<<endl;
    cout<<"1) Venus"<<endl;
    cout<<"2) Earth"<<endl;
    cout<<"3) Mars"<<endl;
    cout<<"4) Jupiter"<<endl;
    cout<<"5) Saturn"<<endl;
    cout<<"6) Uranus"<<endl;
    cout<<"7) Neptune"<<endl;
    cout<<endl;

    cout<<"Which planet do you want to start your delivery"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>userInput;

     if(cin.fail())
    {
        cin.clear();
        cin.sync();

        cout<<"Sorry, the input you gave was not a number, please enter a number"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        pickupPlanet();

    }
    else if(userInput >7 || userInput <0)
    {
        cout<<"Sorry, the input you gave was not a number was not within in the range "<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        pickupPlanet();
    }
    else
    {
        //store string go to the next method
        userShut.setStartPlanet(userInput);
       DPlanet();

    }
}
void DPlanet()
{
int userInput;
cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"0) Mercury"<<endl;
    cout<<"1) Venus"<<endl;
    cout<<"2) Earth"<<endl;
    cout<<"3) Mars"<<endl;
    cout<<"4) Jupiter"<<endl;
    cout<<"5) Saturn"<<endl;
    cout<<"6) Uranus"<<endl;
    cout<<"7) Neptune"<<endl;
    cout<<endl;
    cout<<"Which planet do you want to end your delivery"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>userInput;

     if(cin.fail())
    {
        cin.clear();
        cin.sync();

        cout<<"Sorry, the input you gave was not a number, please enter a number"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        DPlanet();

    }
    else if(userInput >7 || userInput <0)//make sure its within the range
    {

        cout<<"Sorry, the input you gave was not a number was not within in the range "<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        DPlanet();
    }
    else if(userInput == userShut.getStartPlanet())// make sure that the delivery and pick up planets are not the same
    {
         cout<<"Sorry the pick up and delivery planet can't be the same place"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        DPlanet();
    }
    else
    {
        //store string go to the next method
        userShut.setEndPlanet(userInput);
        Weight();


    }
}

void Weight()
{
int userInput;

    cout<<"How much does your delivery weight?"<<endl;
     cout<<"It can't weight more than 10 tons earth or 20000 pounds earth"<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>userInput;

     if(cin.fail())
    {
        cin.clear();
        cin.sync();

        cout<<"Sorry, the input you gave was not a number, please enter a number"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        Weight();

    }
    else if(userInput <=0)//make sure money is not less than 1
    {
        cout<<"Sorry, the input you gave was below or exactly 0, input more than that"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        Weight();
    }
    else
    {
        //store string go to the next method
        userShut.setWeight(userInput);

        calcEarthWeight();
        if(earthWeight<20000)// check to make sure that earth weight is not over 10 tons
        {
            speed();
        }
        else
        {   cout<<"The amount you entered was more than 20000 earth pounds try again"<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;
            Weight();
        }

    }
}

void speed()
{
    int userInput;

     cout<<"How fast is it going?"<<endl;
     cout<<"You can't go faster than 670616629(Speed of light)"<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>userInput;

     if(cin.fail())
    {
        cin.clear();
        cin.sync();

        cout<<"Sorry, the input you gave was not a number, please enter a number"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        speed();

    }
    else if(userInput >670616629||userInput<=0)//not less than one and no faster than the speed of light
    {
        cout<<"Sorry,the input you gave was to0 fast or too slow,please try again"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;

        speed();
    }
    else
    {
        //store string go to the next method
        userShut.setSpeed(userInput);

    }
}

void calcTotalDist()
{
    double x;// used local variables to make the math look easier on the eyes
    double y;

    x=listOfPlanets[userShut.getStartPlanet()].getDistFromSun();
    y=listOfPlanets[userShut.getEndPlanet()].getDistFromSun();

    if(x>y)// make sure I don't get a negative number
    {
         distanceToP=x-y;
    }
    else
    {
         distanceToP=y-x;
    }

}
void calcEarthWeight()
{
    double x;
    double y;

    if(userShut.getStartPlanet() == 2)//if its just earth, set it to earth
    {
        //set earth weight to this
        earthWeight=userShut.getWeight();
    }
    else
    {
        x=listOfPlanets[userShut.getStartPlanet()].getSurfaceGravFactor();
        y=userShut.getWeight();

        earthWeight=y/x;//formula used was (planet surface gravity)/(weight of the item)
    }
}
void calcWeightOtherP()
{
       otherPlanet = earthWeight * listOfPlanets[userShut.getEndPlanet()].getSurfaceGravFactor();//just use earth to calculated the other planets weight

}
void calcTime()
{
     // t= d/v
     hourT = distanceToP/userShut.getSpeed();

     dayT = hourT/24;

     yearT = dayT/365;
}
void writeToFile()
{
    outputFile<<"-----------------------------------------------------------------------"<<endl;
    outputFile<<"Type of Cargo :: "<<userShut.getCargoType()<<endl;
    outputFile<<"Weight of Cargo on starting planet :: "<<listOfPlanets[userShut.getStartPlanet()].getName()<<":: "<<userShut.getWeight()<<endl;
    outputFile<<"Weight of Cargo on ending planet :: "<<listOfPlanets[userShut.getEndPlanet()].getName()<<":: "<<otherPlanet<<endl;
    outputFile<<"Weight of Cargo on Earth :: "<<earthWeight<<endl;
    outputFile<<"The distance traveled :: "<<distanceToP<<endl;
    outputFile<<"How long it will take in hour(s) :: "<<hourT<<endl;
    outputFile<<"How long it will take in day(s) :: "<<dayT<<endl;
    outputFile<<"How long it will take in year(s) :: "<<yearT<<endl;



}

