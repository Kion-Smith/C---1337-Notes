#include <iostream>
#include "windows.h"
using namespace std;

bool isRunning;

char map[10][20]=
{
    "###################",
    "#@                #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "###################"
};

int x=1;
int y=1;

int main()
{
    isRunning = true;

    while(isRunning)
    {
        system("cls");//Clears Screen
        for(int i=0;i<10;i++)
        {
            cout<<map[i]<<endl;
        }
        system("pause>nul");//Fixes flickering without stoping the game( like system(pause) would

        if(GetAsyncKeyState(VK_DOWN))
        {
            int y2 = y+1;

            if(map[y2][x]== ' ')
            {
                map[y][x] = ' ';
                y++;
                map[y][x] = '@';
            }
        }
         if(GetAsyncKeyState(VK_UP))
        {
            int y2 = y-1;

            if(map[y2][x]== ' ')
            {
                map[y][x] = ' ';
                y--;
                map[y][x] = '@';
            }
        }
         if(GetAsyncKeyState(VK_RIGHT))
        {
            int x2 = x+1;

            if(map[y][x2]== ' ')
            {
                map[y][x] = ' ';
                x++;
                map[y][x] = '@';
            }
        }
          if(GetAsyncKeyState(VK_LEFT))
        {
            int x2 = x-1;

            if(map[y][x2]== ' ')
            {
                map[y][x] = ' ';
                x--;
                map[y][x] = '@';
            }
        }

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            isRunning = false;
        }

    }
    system("cls");
    cout<<"END OF THE LINE"<<endl;
    return 0;
}
