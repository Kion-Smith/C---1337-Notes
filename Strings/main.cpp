#include <iostream>
#include <cstring>>
//#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>


using namespace std;
char* safeCopy(char*, const char*);// For anything the program is not going to modify you should make a const
bool isPalin(char *);
string prarseTelPhrase(string);
void formatDollar(string &);
void compressString(char *);
int wordCount(char*);

int main()
{
    try
    {
        /*
        char dPross = 'Y';
        int input;

        while(dPross != 'N')
        {
            cout<<"Please enter and input value"<<endl;
            cin>> input;
            cout<<"Do you want to out put more values"<<endl;
            cin>>dPross;


            if(!isdigit(input)  && !isdigit(dPross))//if something is a number
            {
                cout<<"Special Character"<<endl;
            }
            else
            {
                 cout<<"Thats not a number"<<endl;
            }

            dPross = toupper(dPross);// When you use toupper case dosen't matter
            if(dPross != 'Y' && dPross != 'N')
            {
                cout<<"please enter a valid answer y or n"<<endl;
            }
        }
        cout<<"You answered "<<dPross<<endl;


        const int aSize = 30;
        char line[aSize];//array of chars
        int counter =0;

        cout<<"Enter a line of text"<<endl;
        cin.getline(line,aSize);
        line[16] = '\0';

        //display the users input
        while(line[counter] !='\0')
        {
            cout<<line[counter];

            counter++;
        }
        cout<<endl;
        //c-string  library functions

        const int SIZE = 30;
        char city[SIZE]="Richardson,";
        char state[3] ="TX";

       cout<<"City name has "<<strlen(city)<<" characters"<<endl;//length of char array
       strcat(city,state);//concatinates
       cout<<city<<endl;//displays here
        cout<<"State under reference "<<strstr(city,state)<<endl;//substring aka find the word that you typed,first

        //cstlib header functions
        int iNum = atoi("1234");//Converts to string

        //if you do this :: int iNum = atoi("1234 Plano"); scans the array and will not display the non digits
        //if int iNum = atoi("Plano 1234"); it will do nothing

        cout<<iNum<<endl;


    char text[10] ="Texas";// if the array size is 5 it will throw an error, because its not long enough
    cout<<strlen(text)<<endl;

    //C style strings
    char strA1[30]="Hello welcome to utd.";
    char* strA2 = (char *) "Enjoy your day.";
    //strA1 = strA2; Dosen't work here is an alternative
    safeCopy(strA1,strA2);

    //safeCopy(strA2,strA1);// Cant run both of these at the same time causes a runtime error
    char * text1 ="racecar";
    char * text2 = "Albe was I ere I saw Elba";

    if(isPalin(text2))
    {
        cout<<text2<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Is not"<<endl;
    }






    //DAY 2///////////////////
    //String class

    string userPhrase;
    cout<<"Enter a telephone phrase, and I will convert it to numbers"<<endl;
    cin>>userPhrase;

    string phoneNum = prarseTelPhrase(userPhrase);
    cout<<phoneNum<<endl;



    //EXAMPLE 2

    string dollarA;
    cout<<"Enter a dollar amount,program will format it"<<endl;
    cin>>dollarA;

    formatDollar(dollarA);
    cout<<dollarA<<endl;



    ////DAY 3 ///////////////////////////////
    char testString[] ="aaabbbcc";
    cout<<"The first::  "<<testString<<endl;
    compressString(testString);// WILL WORK UNLESS abc or abbc
    cout<<"The after running::   "<<testString<<endl;
    */

    //New problem
    const int SIZE =81;
    char cString[SIZE];
    string stringObj;

    cout<<"Enter a string word less than 80; This will show the amount of words"<<endl;
    cin.getline(cString,SIZE);


    int counter = wordCount(cString);


    cout<<cString<<". Has a length of "<<counter<<" word count"<<endl;





    }
    catch(exception e)
    {
        cout<<"An error has occurred"<<endl;
        return -1;

    }
    return 0;

}


int wordCount(char* input)
{
    int numOfWords =0;

    while(*input != '\0')
    {
         while(*input != 0 && isspace(*input))
        {
            input++;
        }
        if(*input != 0)// space == 0 in char
        {
            numOfWords++;
        }

        while(*input != 0 && !isspace(*input))
        {
            input++;
        }
    }

    return numOfWords;
}





void compressString(char* input)
{
    char* read = input;
    char* write = input;

    char prevChar = input[0];
    int counter =0;

    while(*read != '\0')
    {
        if(*read == prevChar)
        {
            counter++;
        }
        else
        {
            *write++ == prevChar;// It allows you to increment then do whatever else
            //write++;
            *write++ = counter + '0';
           // *write++;

            //Reset the counter
            counter =1;

        }//end of if
        prevChar=*read;
        read++;
    }// End of while
    *write++ = prevChar;
    *write++ = counter+'0';
    *write='\0';

}


void formatDollar(string & input)
{
    int decimalLoc = (int)input.find('.');//Casted because it was a unsinged long
   // int comaLoc =0;

    //adding commas
    if(decimalLoc>3)
    {
        for(int comaLoc = decimalLoc -3;comaLoc>0;comaLoc -=3)
        {
            input.insert(comaLoc, ",");
        }
    }
    input.insert(0,"$");


}

string prarseTelPhrase(string input)
{
    string telNum = "";
    int norPhone = 10;
    int hyphenPos1 =3,hyphenPos2 =6;

    if(input[0]=='1')
    {
        norPhone++,hyphenPos1++,hyphenPos2++;
    }

    if(input.empty() || input.length() < norPhone)// isEmpty is used by other langauges not c tho
    {
        cout<<"Phone number is too short"<<endl;
        return "Invalid phone phrase";
    }
    int i=0;
    while(i<norPhone)
    {
        if(i==hyphenPos1 || i== hyphenPos2)
        {
            telNum.append("-");
        }
        char currentChar = toupper(input[i]);

        switch (currentChar)
        {
            case '1':
            telNum.append("1");
                break;

            case 'A':
            case 'B':
            case 'C':
                telNum.append("2");
                break;
            case 'D':
            case 'E':
            case 'F':
                telNum.append("3");
                break;

            case 'G':
            case 'H':
            case 'I':
                telNum.append("4");
                break;
            case 'J':
            case 'K':
            case 'L':
                telNum.append("5");
                break;
            case 'M':
            case 'N':
            case 'O':
                telNum.append("6");
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                telNum.append("7");
                break;
            case 'T':
            case 'U':
            case 'V':
                telNum.append("8");
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                telNum.append("9");
                break;

            default:
                telNum += currentChar;
                break;
        }// end switch

        i++;
    }//end while

    return telNum;
}


char* safeCopy(char* str1, const char* str2)// For anything the program is not going to modify you should make a const
{
    cout<<"Target length of string::"<<strlen(str1)<<endl;
    cout<<"And now for the next string::"<<strlen(str2)<<endl;

    if(strlen(str2) > strlen(str1) )
    {
        cout<<"Not enough space for a safe copy"<<endl;
            return str1;
    }

    int i = 0;
    while(str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    cout<<"String copy:: "<< str1<<"|| String 2 :: "<<str2<<endl;
    return str1;

}

bool isPalin(char* input)
{
    int frontI =0;
    int rearI = (int)(strlen(input)-1);

    while(frontI<rearI)
    {

        if(toupper(input[frontI]) != toupper(input[rearI]))
        {
            return false;
        }
        frontI++;
        rearI--;

    }
    return true;
}
