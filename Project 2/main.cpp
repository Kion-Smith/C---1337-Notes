//Kion Smith
//Net ID: kls160430
#include <iostream>
#include<fstream>
#include<string>


using namespace std;


void readAns();
void readCont();
void grade();
void output();

int rightAns = 0;// Used for counting right answers
const int CONSIZE = 5;//size of contestants
const int ASIZE =10; //size of answers
const int total =10;//Size of questions
string* aOfAnswers = new string[ASIZE]; // Array of Answers
string* contestNums = new string[CONSIZE]; // array of contestant nums
string* contestAnswers = new string[CONSIZE]; //array of contestant  answers

string aAns;// String to hold the answers

struct Contestants
{
    string id;
    string inncorrect;//String of wrong answers
    string correct;//right answers
    int gotRight; // how many contestant got right
    int finalScore; // The score of the contestant

};
Contestants cont[CONSIZE];// Array of structs of contestants



int main()
{

    readAns();
    readCont();
    grade();
    output();
    cout<<"CHECK THE TEXT FILE reports.txt"<<endl;





    return 0;
}
void readAns() //Read Text file
{
    ifstream fileAnswers ("Answers.txt");
    string stringAnswers;
    string rightAnswers;


    int i=0;
     if(fileAnswers.is_open())
    {

        while(getline(fileAnswers,stringAnswers))
        {


            *(aOfAnswers+i)=stringAnswers.substr(stringAnswers.find(" ")+1,stringAnswers.length()-1) ;// Creating an array of answers
            i++;


        }


    }

    else
    {
        cout<<"The file failed to open"<<endl;
    }
    fileAnswers.close();

}
void readCont() //read other inputfile
{
    ifstream fileContestants ("Contestants.txt");

    string contestantNums;
    string stringContestants;



    if(fileContestants.is_open())
    {
        int i=0;
        while(getline(fileContestants,stringContestants))
        {

            *(contestNums+i)= stringContestants.substr(0,stringContestants.find(" ")+1);//Adding Contestant numbers to an array

           *(contestAnswers+i)=stringContestants.substr(stringContestants.find(" ")+1,stringContestants.length()-1);// adding all the answers to 1 array


            i++;

        }


    }
    else
    {
        cout<< "The file failed to open"<<endl;
    }
    fileContestants.close();

}
void grade()// Grade all the contestants
{
        string tempString1;
        string tempString2;
        string temp3;
        string temp4;

    for(int i=0;i<ASIZE;i++)
    {
        aAns += *(aOfAnswers+i) +" ";
    }
   // cout<<aAns<<endl;

    for(int i=0; i<aAns.length()-1;i++)
    {   tempString1 = aAns.at(i);
        tempString2 = contestAnswers[0].at(i);

        if(aAns.at(i)==contestAnswers[0].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            //cout<<aAns.at(i)<<"=="<<contestAnswers[0].at(i)<<endl;

            rightAns++;
        }
        else if(aAns.at(i)!=contestAnswers[0].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            temp3 += contestAnswers[0].at(i);
            temp4 += aAns.at(i);

        }
    }
   // cout<< temp3<<endl;
    cont[0].inncorrect= temp3;
    cont[0].correct = temp4;
    temp3 ="";
    temp4 ="";
   // cout<< temp4<<endl;
    cont[0].gotRight = rightAns;
   // cout<<rightAns<<endl;
    //2
    rightAns=0;
    for(int i=0; i<aAns.length()-1;i++)
    {   tempString1 = aAns.at(i);
        tempString2 = contestAnswers[1].at(i);

        if(aAns.at(i)==contestAnswers[1].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
           // cout<<aAns.at(i)<<"=="<<contestAnswers[1].at(i)<<endl;

            rightAns++;
        }
         else if(aAns.at(i)!=contestAnswers[1].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            temp3 += contestAnswers[1].at(i);
            temp4 += aAns.at(i);
        }
    }
  //  cout<< temp3<<endl;
    cont[1].inncorrect= temp3;
    cont[1].correct = temp4;
    temp3 ="";
    temp4 ="";
   // cout<<rightAns<<endl;
    cont[1].gotRight = rightAns;
    //3
    rightAns=0;
    for(int i=0; i<aAns.length()-1;i++)
    {   tempString1 = aAns.at(i);
        tempString2 = contestAnswers[2].at(i);

        if(aAns.at(i)==contestAnswers[2].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
         //   cout<<aAns.at(i)<<"=="<<contestAnswers[2].at(i)<<endl;

            rightAns++;
        }
         else if(aAns.at(i)!=contestAnswers[2].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            temp3 += contestAnswers[2].at(i);
            temp4 += aAns.at(i);
        }

    }
   // cout<< temp3<<endl;
    cont[2].inncorrect= temp3;
    cont[2].correct = temp4;
    temp3 ="";
    temp4 ="";
  // cout<<rightAns<<endl;
    cont[2].gotRight = rightAns;
    //4
    rightAns=0;
    for(int i=0; i<aAns.length()-1;i++)
    {   tempString1 = aAns.at(i);
        tempString2 = contestAnswers[3].at(i);

        if(aAns.at(i)==contestAnswers[3].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
      //      cout<<aAns.at(i)<<"=="<<contestAnswers[3].at(i)<<endl;

            rightAns++;
        }
         else if(aAns.at(i)!=contestAnswers[3].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            temp3 += contestAnswers[3].at(i);
            temp4 += aAns.at(i);
        }
    }
    //cout<< temp3<<endl;
    cont[3].inncorrect= temp3;
    cont[3].correct = temp4;
    temp3 ="";
    temp4 ="";
    //cout<<rightAns<<endl;
    cont[3].gotRight = rightAns;

    //5
    rightAns=0;
    for(int i=0; i<aAns.length()-1;i++)
    {   tempString1 = aAns.at(i);
        tempString2 = contestAnswers[4].at(i);

        if(aAns.at(i)==contestAnswers[4].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
           // cout<<aAns.at(i)<<"=="<<contestAnswers[4].at(i)<<endl;

            rightAns++;
        }
        else if(aAns.at(i)!=contestAnswers[4].at(i)&& tempString1 != " "&& tempString2 !=" ")
        {
            temp3 += contestAnswers[4].at(i);
            temp4 += aAns.at(i);
        }
    }
    //cout<< temp3<<endl;
    cont[4].correct = temp4;
     cont[4].inncorrect= temp3;
    temp3 ="";
    temp4 ="";
    cont[4].gotRight = rightAns;
   // cout<<rightAns<<endl;
}

void output()// final operation to make the textfile
{


     int mean;
     int mode;
     int median;




    ofstream outputFile ("report.txt");//Create file
    for(int i =0;i<ASIZE;i++)
    {


    }
    for(int i=0;i<CONSIZE;i++) // Using array of structs to out put to file
    {
        cont[i].finalScore = (double)cont[i].gotRight/total * 100;

        outputFile<<"Contestant #"<<i+1<<"::"<<*(contestNums+i)<<endl;
        outputFile<<"There Score was :: "<<cont[i].finalScore<<endl;
        //outputFile<<"They answered::"<<contestAnswers[i]<<endl;
        outputFile<<"The incorrect answers were:: "<< cont[i].inncorrect<< endl;
        outputFile<<"The right answer was      :: "<<cont[i].correct<<endl;
        outputFile<<"They got "<<cont[i].gotRight<<endl;

        outputFile<<endl;
        mean += cont[i].gotRight;


    }
    int counter;
    //Look for the mode
    for(int i =0;i<CONSIZE;i++)
    {
        if(cont[i].gotRight == mode)
        {
            counter++;

        }
        else
        {
            mode = cont[i].gotRight;
        }
    }
    int place=CONSIZE/2;
    median = cont[place].gotRight;
    //cout<<median<<endl;
    mean = mean/CONSIZE;
    //cout<<mean<<endl;
   // cout<< mode<<endl;

    outputFile<<"The Mean of correct answers was :: "<< mean<<endl;
    outputFile<<"The median of the correct answer was ::"<<median<<endl;
    outputFile<<"The mode of correct answers was ::"<<mode<<endl;


    outputFile.close();

    //Deleting arrays to free up memory
    delete [] aOfAnswers;
    delete [] contestAnswers;
    delete [] contestNums;

}
