#include <iostream>

using namespace std;

void swapP(int*,int*);

int main()
{
    try
    {

        int var =20;
        long longVar = 909876L;

        cout << "My numbers value is "<< var <<""<<endl;
        cout << "My numbers memory address is " << &var<< endl;

        int *pointerInt;
        pointerInt= &var;

        cout <<"pointer is pointing to this address "<< pointerInt << endl;
        cout <<"pointers value is "<<*pointerInt << endl;



         var += 5;
         cout<<"Changed the value of my var to "<<*pointerInt<<endl;

         *pointerInt =89;// changes the value of all of var

         cout<< "Changed my pointer to equal "<<*pointerInt<<endl;

         pointerInt++;// This will move to the next memory location

         cout <<"I used ++ on my pointer and it equals " <<*pointerInt<<endl;
         cout << "The address of my pointer is now " << pointerInt<<endl;



         //////////DAY 2//////////////////////
        cout << endl;
        cout << "//////////////////////DAY 2//////////////////"<< endl;
        cout << endl;
         /*
         Arrays an pointer function in the same way


         */


         const int SIZE = 10;
         int myArray[SIZE] = { 42,2,3,40,50,2,87,20,6,83};

         cout << "The index of the array's first element "<<myArray << endl;
         cout << "Here is the proof "<<*myArray << endl;



         for(int i =0; i<SIZE;i++)
         {
             cout << i+1 << ". Element = " << myArray[i] <<endl;
             cout << i+1 << ":: Element using pointers :: " << *(myArray +i) <<endl;// Need the () or else it will just add to the first element of the array
             cout << i+1 << " elements index is || " << &myArray[i] <<endl;

         }

         cout << "OUT OF BOUNDS ::" << *(myArray +SIZE) <<endl;//Prints random value

         int *reversePtr = myArray + SIZE -1;

        cout<< "The last element of the the array is ( I am using pointers) ::" << *reversePtr<<endl;

        for(int c = 0; c< SIZE;c++)
        {

            cout << c+1 << ") Reverse element is "<< *(reversePtr - c) <<endl; // Getting the reverse of the array
            /*

            OR
                c--;
                cout << c+1 << ") Reverse element is "<< *(reversePtr)<< endl;
            }

                do not add  (c-- )it after because you will cause the value to change;
            */
        }

        cout << "The end point is still "<<*reversePtr<< endl;
        int *valuePtr = myArray;

        if(valuePtr == reversePtr)
        {
            cout <<" The pointers are both pointing to the same element in the array" << endl;
        }
        else
        {
            cout<<"Value of valuePtr = " << valuePtr<< " While reversePtr =" << reversePtr<<endl;// prints the location
        }

        if(*valuePtr == *reversePtr)
        {
            cout <<" The pointers are both pointing to the same element in the array" << endl;
        }
        else
        {
            cout<<"Value of valuePtr = " << *valuePtr<< " While reversePtr =" << *reversePtr<<endl;// prints the
        }

        int num1 = 35, num2 = 60;
        int *ptr1=&num1;
        int *ptr2 = &num2;

        cout<< "Before : ptr1 (address) = "<< ptr1<<" ptr1 value = "<< *ptr1<< endl;
        cout<< "Before : ptr2 (address) = "<< ptr2<<" ptr2 value = "<< *ptr2<< endl;

        swapP(ptr1,ptr2);
        cout<< "After : ptr1 (address) = "<< ptr1<<" ptr1 value = "<< *ptr1<< endl;
        cout<< "After : ptr2 (address) = "<< ptr2<<" ptr2 value = "<< *ptr2<< endl;
        // Only passes value not the location


        //////////////////DAY 3///////////////////////////////

        // When you want to dynamically store data use new
        float myFloat = 12.3f; //staticaly aloucated  memory at compile time
        float* floatPtr = new float();// new operator returns the address of the dynamically allocated memeonry

        *floatPtr= 18.3f;
        cout <<"The dynamically stored value is::" << *floatPtr<<endl;

        // Release the memory when you are done with it, so the operator can use it again and avoid memory leaks

        //floatPtr = nullptr;
        delete floatPtr;

        // Dynamic array////

        const int SIZEs = 10;
        double* myDArray = new  double [SIZEs];// Making it dynamicallly

/*
        for(int i = 0; i< SIZEs;i++)
        {

            myDArray[i] = i * i;
            cout << myDArray[i] << endl; //using array syntax
        }


*/

        for(int i = 0; i<SIZEs;i++)
        {


            myDArray[i] = i * i;
            cout << *(myDArray+i) << endl; //using array syntax
        }

        delete [] myDArray;
        //myDArray = nullptr; <-- Need to add to some header file or some shit

        cout<< "Even after deleting the  array my array is still pointing to::" << *myDArray <<endl;

        if(myDArray)
        {

            cout<<"Its still valid"<<endl;
        }
        else
            cout<<"Not valid"<<endl;
// Pointer to constant - Can be changed it to somthing else, but you can derfrance it on update
//

    }

    catch(exception e)
    {
       cout << "An error"<<endl;
        return -1;
    }

    return 0;
}

void swapP(int *pointer1,int *pointer2)
{
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;


}
