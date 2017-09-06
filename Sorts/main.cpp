#include <iostream>

using namespace std;

void showArray(int array[],int);
void bubbleSort(int array[],int);
void selectionSort(int array[],int);

int main()
{
    try
    {

    int randNums[] = {1,22,13,2,51,9};




    int sizeOfArray = sizeof(randNums)/4;

    showArray(randNums,sizeOfArray);


    //bubbleSort(randNums,sizeOfArray);
    selectionSort(randNums,sizeOfArray);




   showArray(randNums,sizeOfArray);




    }
    catch(exception e)
    {
        cout <<"Error"<< endl;

        return -1;
    }



    return 0;
}
void showArray(int array[],int size)
{
    for(int i=0; i<size;i++)
    {

        cout<< array[i] <<" ";

    }
        cout<<endl;
}
void bubbleSort(int array[],int size)
{
    bool swap;
    int temp;

    int numOfSwap;

   do
    {
       swap = false;
       for (int count = 0; count < size; count++)
       {
          if (array[count] > array[count + 1])
          {
              temp = array[count];
              array[count] = array[count + 1];
              array[count + 1] = temp;
              swap = true;
        }
       }
    }
    while (swap);
    {


    }


}
void selectionSort(int array[],int size)
{
    int startScan, minIndex, minValue,counter;
    for (startScan = 0; startScan < size; startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];

        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;



            }


        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;

    }

cout<< counter<<endl;
}






