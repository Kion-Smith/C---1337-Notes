
#include <iostream>
#include <iomanip>

using namespace std;

int ReadSquareSize();
void OddMagicSquare(int** matrix, int n);
void DoublyEvenMagicSquare(int** matrix, int n);
void SinglyEvenMagicSquare(int** matrix, int n);
void MagicSquare(int** matrix, int n);
int** CreateMatrix(int n);
void FreeMatrix(int** matrix, int n);

int main(int argc, char* argv[])
{
  int i,n;
  n = ReadSquareSize();

  int** matrix = CreateMatrix(n);

  MagicSquare(matrix, n);

  // print the square
  for(int i=0; i<n ;i++)
  {
      for(int j=0; j<n ; j++)
      {
      cout<<setiosflags(ios::left) << setw (5) << matrix[i][j];
      }
      cout<<endl;
  }



  return 0;
}


int ReadSquareSize()
{
    int x;
    cout<<"Enter a positive integer square size of 3 or more: ";
    while(1)
    {
        cin>>x;
        if(x>=3)
        {
            return x;
        }
        else
        {
            cout<<"Enter a positive integer square size of 3 or more: ";
        }
    }
    cout<<endl;
}

void MagicSquare(int** matrix,int n)
{
  //if (n%2==1)        //n is Odd
    OddMagicSquare(matrix, n);
}

void OddMagicSquare(int** matrix, int n)
{
  int nsqr = n * n;
  int i=0, j=n/2;     // start position

  for (int k=1; k<=nsqr; ++k)
  {
    matrix[i][j] = k;

    i--;
    j++;

    if (k%n == 0)
    {
      i += 2;
      --j;
    }
    else
    {
      if (j==n)
        j -= n;
      else if (i<0)
        i += n;
    }
  }
}




int** CreateMatrix(int n)
{
  int i;
  int** matrix = new int* [n];
  for(i=0;i<n;i++)
  {
        matrix[i] = new int[n];
  }
  return matrix;
}



