// This program demonstrates the searchList function, which   2  // performs a linear search on an integer array.
#include <iostream>
using namespace std;

// Function prototype
int searchList(const int [], int, int);
const int SIZE = 5;

int main()
{
int tests[SIZE] = {87, 75, 98, 100, 82};
int results;

results = searchList(tests, SIZE, 100);

 if (results == 0)
 {
     cout << "You did not earn 100 points on any test\n";
 }

    else
    {
        cout << "You earned 100 points on test ";
        cout << (results + 1) << endl;
    }
     return 0;
}

 int searchList(const int list[], int numElems, int value)
 {
   int index = 0;        // Used as a subscript to search array
   int position = 0;    // To record position of search value
   bool found = false;  // Flag to indicate if the value was found
   while (index < numElems && !found)
   {
      if (list[index] == value)   // If the value is found
      {
         found = true;         // Set the flag
         position = index;     // Record the value's subscript
      }
      index++;                  // Go to the next element
   }
   return position;               // Return the position, or −1  }
}
