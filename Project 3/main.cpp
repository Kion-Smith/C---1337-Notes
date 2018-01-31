//NAME: Kion Smith
//NET-ID:kls160430
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

unsigned short userInput;// Global varible for user inputs
//Methods used within the project
void getMagicNum();
void  createMagicNumTable(unsigned short,int**);
int** createMatrix(unsigned short);
void printToTextFile(int,int**,int);
ofstream outputFile ("MagicSquares.txt");//created the text file here to make sure that it keeps writing

int main()
{

   try
   {    cout<<"All results can be found in MagicSquares.txt as well as within the console"<<endl;
        cout<<endl;
        getMagicNum();

      return 0;
   }
   catch(exception e)
   {
       cout<<"An error has occurred"<<endl;
       return -1;
   }

}

void getMagicNum()// Checks to make sure that user inputs are correct and runs the rest of the methods
{
     cout<<"Enter any odd number between 1-999"<<endl;//Collect the input
    cin>>userInput;

       if(cin.fail()) // if the input is not number out put this
       {
           cout<<"Please enter a numeric value"<<endl;
           cin.clear();
           cin.sync();
            getMagicNum();
       }
       else if(userInput== 0)// When 0 terminate the program
       {
           cout<<"Terminating Program"<<endl;
           outputFile.close();
       }
       else if(userInput % 2 == 0) // if its not an odd number out print this
       {
           cout<<"This is a even number,please input an odd number"<<endl;
           getMagicNum();
       }
       else
        {
            int** matrix = createMatrix(userInput);
            createMagicNumTable(userInput,matrix);
            getMagicNum();
        }
}

void createMagicNumTable(unsigned short input,int** matrix)// Creates the table using 2d array, which is created in another method for quicker and better results
{
  int sqr = input * input;// Create the square
  int i=0;
  int j= input/2;// Starting postions

  for (int x=1; x<= sqr;x++ )
    {
        matrix[i][j] = x;

        i--;
        j++;

        if (x%input == 0)
        {
            i += 2;
            j--;
        }
        else
            {
                if (j==input)
                {
                    j -= input;
                }

                else if (i<0)
                {
                    i += input;
                }

            }
    }
    //Look for the highest number
    int maxnum =0;
    for(int i=0;i<input;i++)
    {
        for(int x =0;x<input;x++)
        {
           if(maxnum<matrix[i][x])
           {
               maxnum = matrix[i][x];
           }
        }
    }

    int counter =0;
    while(maxnum) //use highest number to determine the size of setw
    {
        maxnum = maxnum/10;
        counter++;
    }
    for(int i=0;i<input;i++)
    {
        for(int x =0;x<input;x++)
        {
           cout<<setw(counter)<<matrix[i][x]<<" ";
        }
        cout<<endl;
    }
     int magicSum;
        magicSum = input*(input*input+1)/2;
        cout<<"The magic sum is::"<<magicSum<<endl;
    printToTextFile(counter,matrix,input);
    cout<<endl;
}
int** createMatrix(unsigned short x) // Creates a matrix outside of the create table method because it improves run time and the amount of variables
{
      int** matrix = 0;

      matrix = new int*[x];
      for (int i = 0; i < x; i++)
      {
            matrix[i] = new int[x];
      }
      for(int i=0;i<5;i++)
    {
        for(int x =0;x<5;x++)
        {
           cout<<matrix[i][x]<<" "<<endl;
        }
    }

      return matrix;
    }

    void printToTextFile(int length,int** matrix,int input)// Print results to a txt file
    {
        int magicSum;
        magicSum = input*(input*input+1)/2;// Egaution for magic sum
        outputFile<<"This is for ::"<<input<<endl;
        outputFile<<"And is magic sum is::"<<magicSum<<endl;
        outputFile<<endl;
        for(int i=0;i<input;i++)
        {
        for(int x =0;x<input;x++)
            {
                outputFile<<setw(length)<<matrix[i][x]<<" ";
            }
            outputFile<<endl;
        }
        cout<<input<<" magic square was added to the output file MagicSquares.txt"<<endl;
        outputFile<<endl;
        outputFile<<endl;

    }

