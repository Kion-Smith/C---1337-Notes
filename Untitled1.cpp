#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;



inline void Refresh(char q[50][50]){
system("cls");
int i, j;
cout << endl;
for (i = 0; i < 50; i++) {
    cout << "\t";
    for (j = 0; j < 50; j++)
    {
        cout << q[i][j];
    }
    cout << endl;
}
}


int launch(char q[][50], int a1, int a2, int p1, int p2, int x0, int y0);

//**************************Main Function*********************************************
int main(){
char map[50][50] = {
    "#################################################",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#                                               #",
    "#################################################"
};
// my character
int x0 = 1, y0 = 1;



// Randomly make and spawn the holes
int a1, a2;
srand(time(0));
do {
    a1 = rand() % 48 - 1;
    a2 = rand() % 48 - 1;
} while (map[a1][a2] != ' ');
map[a1][a2] = 'O';

// Randomly make and spawn the zombies
int p1, p2;
srand(time(0));
do {
    p1 = rand() % 48 - 1;
    p2 = rand() % 48 - 1;
} while (map[p1][p2] != ' ');
map[p1][p2] = 'Z';


launch(map, a1, a2, p1, p2, x0, y0);

 }


int launch(char q[][50], int a1, int a2, int p1, int p2,int x0, int y0){
int over, x = x0, y = y0;
while (1) // Infinite loop
{
    _getch();

    // UP key
    if (GetAsyncKeyState(VK_UP))
    {
        x = x - 1;
    }
    // DOWN key
    else if (GetAsyncKeyState(VK_DOWN))
    {
        x = x + 1;
    }
    // LEFT key
    else if (GetAsyncKeyState(VK_LEFT))
    {
        y = y - 1;
    }
    // RIGHT key
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        y = y + 1;
    }


    if (x == 0 || x == 50 || y == 0 || y == 50)
    {
        cout << "Game Over" << endl;
        return 0;
    }

    if (x == p1 && y == p2) { // Touch the zombies
        cout << "Game Over" << endl;
        system("PAUSE");
        return 0;
    }

    if (x == a1 && y == a2) { // Touch the holes
        cout << "Game Over" << endl;
        system("PAUSE");
        return 0;
    }

    else { // the hero just moving around
        q[x0][y0] = ' ';
        q[x][y] = 'M';

        Refresh(q);
    }
    x0 = x;
    y0 = y;

}
return 0;
}
