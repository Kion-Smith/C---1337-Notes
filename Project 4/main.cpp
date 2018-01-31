/*
    BY KION SMITH
    NET ID: kls160430
    COURSE: CS1337
    SECTION: 010
    PROJECT NUMBER 4
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void start(string*,int*,int*);// Main menu, leads to all options expect preGame();
void preGame();// The runner method
void again();// Allows the player to continue playing

void betSingleNums(string*,int*,int*);// bet a on a single number
void betColors(string*,int*,int*);//be on black or red
void betEvenOdd(string*,int*,int*);// bet on even or odd
void bet12(string*,int*,int*);// be on the first,second, or last 12
void betHalf(string*,int*,int*);// bet on half the board
void betColumn(string*,int*,int*);//bet on first,second,or last column

void spin(string*,int*,int*);//Spins the wheel

int* createArray();//Create dynamic array of int
string* stringArray();//Create dynamic array of strings

int startMoney =0;// Orginal money
int temMoney=0;//Copy of orginal money, but used to make sure the player does not go over what they have
int winnings=0;// Winning from the whole game
int numOfBets =0;// How many bets have been places

int main()
{


    try
    {
        cout<<"Welcome to the Roulette Wheel player!"<<endl;
        preGame();//start the game

    }
    catch(exception e)
    {
        cout<<"An error has occurred"<<endl;
    }
    return 0;
}

void preGame()
{
    cout<<"How much money do you want to use to play with?"<<endl;
    cout<<"There is a maximum of $10,000"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
     cin>>startMoney;
    if(cin.fail())// If cin faills then run the rest
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        preGame();
    }
    else if(startMoney <= 0)// money is not 0 or less
    {
        cout<<"Sorry you do not have enough money to play, please input numbers above 0"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        preGame();
    }
    else if(startMoney > 10000)// Money is not more than the max
    {
        cout<<"The amount you entered was too much,please select an amount between $1 - $10,000"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        preGame();
    }
    else
    {
        string* typeOfBet = stringArray();// Create my Type array
         int* moneyInBet = createArray();// Create my money array
         int* betInput =createArray();// Create my bet array
         temMoney=startMoney;//Copy startMoney

        start(typeOfBet,moneyInBet,betInput);// run the menu
    }
}

int* createArray()
{
    int const bet =8;
     int *intarray = new int[bet];// empty array

      return intarray;
}

string* stringArray()
{
    int const bet =8;
     string *strarray = new string[bet];//empty array

      return strarray;
}


void start(string* type,int* money,int* input)

{   int userInput =0;

    if(numOfBets != 8 && !temMoney <=0)
    {
    cout<<"You can have bet "<<numOfBets<<" times out of 8"<<endl;
    cout<<"You have $"<<temMoney<<" left"<<endl;
    cout<<endl;
    cout<<"Here are the options for betting"<<endl;
    cout<<endl;
    cout<<"1)Bet on a single number (0-36) - pays $35 for ever $1"<<endl;
    cout<<"2)Bet on red or black - pays $1 for ever $1"<<endl;
    cout<<"3)Bet on an even or odd number - pays $1 for ever $1"<<endl;
    cout<<"4)Bet on (1-12),(13-24),or(25-36) - pays $2 for ever $1"<<endl;
    cout<<"5)Bet on (1-18) or (19-36) - pays $1 for ever $1"<<endl;
    cout<<"6)Bet on the first,second,or third columns - pays $2 for every $1 "<<endl;
    cout<<"7) Spin"<<endl;
    cout<<endl;
    cout<<"Which one do you want to do"<<endl;
    cin>>userInput;
    cout<<"-----------------------------------------------------------------------"<<endl;

    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        start(type,money,input);
    }
    else if(userInput>7 || userInput <=0)// Make sure input is one from them menu
    {
        cout<<"Please choose a valid input in the menu"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        start(type,money,input);
    }
    else if(userInput == 1)// All these else statements to determine which method to use
    {
        betSingleNums(type,money,input);
    }
    else if(userInput == 2)
    {
        betColors(type,money,input);
    }
    else if(userInput == 3)
    {
        betEvenOdd(type,money,input);
    }
    else if(userInput == 4)
    {
        bet12(type,money,input);
    }
    else if(userInput == 5)
    {
        betHalf(type,money,input);
    }
    else if(userInput == 6)
    {
        betColumn(type,money,input);
    }
    else if(userInput == 7 && numOfBets>0)
    {
        spin(type,money,input);
    }
}
else if(temMoney <=0)// if money is 0 or less
{
    int temp =0;
    cout<<"You can only spin"<<endl;
    cout<<"0) Spin"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>temp;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        start(type,money,input);
    }
    else if(temp !=0)//valid input
    {
        cout<<"Please choose a valid input in the menu"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        start(type,money,input);
    }
    else
    {
        spin(type,money,input);
    }
}
else
{
    cout<<"You can only spin because you have "<< numOfBets<<" number of bets left for this spin"<<endl;
    cout<<"And because you have $"<< temMoney<<" left"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    spin(type,money,input);


}

}

void betSingleNums(string* type,int* money,int* input)// Single number bets
{
    int tempInput=0;
    int tempMoney =0;

    cout<<"Choose a number between 0-36"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betSingleNums(type,money,input);
    }
    else if(tempInput < 0)//bounds for 0
    {
        cout<<"that number is not on the board,input a number either equal to 0 or higher"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        betSingleNums(type,money,input);
    }
    else if(tempInput > 36)// bounds for 36
    {
        cout<<"that number you enter is not on the board,input a number either equal to 36 or higher"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betSingleNums(type,money,input);
    }




    cout<<"How much do you want to bet. Max bet is 500"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempMoney;
    if(cin.fail())
    {
    cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betSingleNums(type,money,input);
                    }
                    else if(tempMoney < 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        betSingleNums(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betSingleNums(type,money,input);
                    }
                    else if(temMoney-tempMoney <0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         betSingleNums(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "Single";//set this position to  single
                        money[numOfBets]= tempMoney;//set positions to the Money
                        input[numOfBets]= tempInput;//set position to  input

                       numOfBets++;//incrimination of bets

                       temMoney=temMoney-tempMoney;// keep track of money
                       start(type,money,input);
                    }



}
void betColors(string* type,int* money,int* input)
{
    int tempInput =0;
    int tempMoney =0;
    cout<<"Which color do you want to choose?"<<endl;
    cout<<"0)RED"<<endl;
    cout<<"1)BLACk"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betColors(type,money,input);
    }
    else if(tempInput>1|| tempInput<0)
    {
        cout<<"The number you input was higher/lower than either choice"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        betColors(type,money,input);
    }
    else
    {
        cout<<"How much do you want to bet. Max bet is 500"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cin>>tempMoney;
                 if(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betColors(type,money,input);
                    }
                    else if(tempMoney< 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        betColors(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betColors(type,money,input);
                    }
                    else if(temMoney-tempMoney < 0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         betColors(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "Colors";
                        money[numOfBets]= tempMoney;
                        input[numOfBets]= tempInput;

                        temMoney=temMoney-tempMoney;

                       numOfBets++;
                       start(type,money,input);
                    }
    }
}
void betEvenOdd(string* type,int* money,int* input)
{
    int tempInput =0;
    int tempMoney =0;
    cout<<"Do you want to choose even or odd numbers?"<<endl;
    cout<<"0)EVEN"<<endl;
    cout<<"1)ODD"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betEvenOdd(type,money,input);
    }
    else if(tempInput>1|| tempInput<0)
    {
        cout<<"The number you input was higher/lower than either choice"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        betEvenOdd(type,money,input);
    }
    else
    {
        cout<<"How much do you want to bet. Max bet is 500"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cin>>tempMoney;
                 if(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betEvenOdd(type,money,input);
                    }
                    else if(tempMoney < 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        betEvenOdd(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betEvenOdd(type,money,input);
                    }
                    else if(temMoney-tempMoney < 0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         betEvenOdd(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "EvenOdd";
                        money[numOfBets]= tempMoney;
                        input[numOfBets]= tempInput;

                        temMoney=temMoney-tempMoney;

                       numOfBets++;
                       start(type,money,input);
                    }


    }
}
void bet12(string* type,int* money,int* input)
{
    int tempInput =0;
    int tempMoney =0;
    cout<<"Do you want to bet on first,second or third 12's?"<<endl;
    cout<<"0)First (1-12)"<<endl;
    cout<<"1)Second (13-24)"<<endl;
    cout<<"2)Third (25-36)"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       bet12(type,money,input);
    }
    else if(tempInput>2|| tempInput<0)
    {
        cout<<"The number you input was higher/lower than either choice"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        bet12(type,money,input);
    }
    else
    {
        cout<<"How much do you want to bet. Max bet is 500"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cin>>tempMoney;
                 if(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       bet12(type,money,input);
                    }
                    else if(tempMoney < 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        bet12(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       bet12(type,money,input);
                    }
                    else if(temMoney-tempMoney < 0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         bet12(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "12's";
                        money[numOfBets]= tempMoney;
                        input[numOfBets]= tempInput;

                        temMoney=temMoney-tempMoney;

                       numOfBets++;
                       start(type,money,input);
                    }


    }
}
void betHalf(string* type,int* money,int* input)
{
    int tempInput =0;
    int tempMoney =0;
    cout<<"Do you want to bet on the first half (1-18) or second (19-36)"<<endl;
    cout<<"0)First(1-18)"<<endl;
    cout<<"1)Second(19-36)"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betHalf(type,money,input);
    }
    else if(tempInput>1|| tempInput<0)
    {
        cout<<"The number you input was higher/lower than either choice"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        betHalf(type,money,input);
    }
    else
    {
        cout<<"How much do you want to bet. Max bet is 500"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cin>>tempMoney;
                 if(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betHalf(type,money,input);
                    }
                    else if(tempMoney < 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        betHalf(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betHalf(type,money,input);
                    }
                    else if(temMoney-tempMoney < 0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         betHalf(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "Half";
                        money[numOfBets]= tempMoney;
                        input[numOfBets]= tempInput;

                        temMoney=temMoney-tempMoney;

                       numOfBets++;
                       start(type,money,input);
                    }


    }

}
void betColumn(string* type,int* money,int* input)
{
   int tempInput =0;
    int tempMoney =0;
    cout<<"Do you want to bet on first,second or third columns"<<endl;
    cout<<"0)First"<<endl;
    cout<<"1)Second"<<endl;
    cout<<"2)Third"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cin>>tempInput;
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
       betColumn(type,money,input);
    }
    else if(tempInput>2|| tempInput<0)
    {
        cout<<"The number you input was higher/lower than either choice"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        betColumn(type,money,input);
    }
    else
    {
        cout<<"How much do you want to bet. Max bet is 500"<<endl;
        cin>>tempMoney;
                 if(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betColumn(type,money,input);
                    }
                    else if(tempMoney < 0)
                    {
                        cout<<"You entered less than a dollar or no money at all, please add more money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                        betColumn(type,money,input);
                    }
                    else if(tempMoney > 500)
                    {
                        cout<<"You enter more than the max amount of money"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                       betColumn(type,money,input);
                    }
                    else if(temMoney-tempMoney < 0)
                    {
                        cout<<"The amount you entered is more than you have,please enter less"<<endl;
                        cout<<"-----------------------------------------------------------------------"<<endl;
                         betColumn(type,money,input);
                    }
                    else
                    {


                        type[numOfBets] = "Columns";
                        money[numOfBets]= tempMoney;
                        input[numOfBets]= tempInput;

                        temMoney=temMoney-tempMoney;

                       numOfBets++;
                       start(type,money,input);
                    }


    }
}
void spin(string* type,int* money,int* input)
{
    int tempInput =0;
    srand(time(NULL));

    int ans1 =  0;
    int ans2 =  0;
    int ans3 =  0;
    int ans4 =  0;
    int ans5 =  0;
    int ans6 =  0;


    //Creating random answers for inputs
    ans1 =  rand()%37+1;
    ans2 =  rand()%2;
    ans3 =  rand()%2;
    ans4 =  rand()%3;
    ans5 =  rand()%2;
    ans6 =  rand()%3;


    for(int i=0;i<8;i++)
    {
        if(type[i]=="Single" && input[i]==ans1)
        {
            winnings += (money[i] *35)+ money[i];

        }
        if(type[i]=="Colors"&& input[i]==ans2)
        {
           winnings += (money[i] *1)+ money[i];

        }
        if(type[i]=="EvenOdd"&& input[i]==ans3)
        {
            winnings += (money[i] *1)+ money[i];

        }
        if(type[i]=="12's"&& input[i]==ans4)
        {
            winnings += (money[i] *2)+ money[i];

        }
        if(type[i]=="Half"&& input[i]==ans5)
        {
            winnings += (money[i] *1)+ money[i];

        }
        if(type[i]=="Columns"&& input[i]==ans6)
        {
            winnings += (money[i] *2)+ money[i];

        }

    }

    cout<<"You won "<< winnings<<" from these spins!"<<endl;

    //get rid of the array

   delete[] type;
   delete[] money;
   delete[] input;

    again();//play again

}

void again()
{
 int tempInput =0;
    cout<<"Do you want to play another round?"<<endl;
   cout<<"0) Play"<<endl;
   cout<<"1) Leave"<<endl;
   cout<<"-----------------------------------------------------------------------"<<endl;
   cin>>tempInput;

    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Sorry, the input you gave was not numeric,please input numbers"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        again();
    }
    else if(tempInput<= 0)
    {
        cout<<"Sorry your answer was not within the range, enter a number with in it"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        again();
    }
    else if(tempInput ==0)
    {
        string* Newtype = stringArray();//new array
         int* Newmoney = createArray();//new array
         int* NewInput =createArray();//new array

        numOfBets =0;
        start(Newtype,Newmoney,NewInput);
    }
    else
    {
        int endMoney = startMoney+winnings;
        cout<<"You started with "<<startMoney<<" and ended with "<<endMoney<<" gaining "<<winnings<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
    }


}

