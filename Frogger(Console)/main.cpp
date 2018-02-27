#include <iostream>
#include "windows.h"

using namespace std;

void car1();

bool isRunning;

int y=11;
int x =6;

struct carsInfo
{
    int y,x,otherx;
};
struct carsInfo car[3];

char map[13][14] =
{
    "#############",
    "## # # # # ##",
    "#-===--==---#",
    "#O---OO--OO-#",
    "#--==---====#",
    "#--OOO---OOO#",
    "#===========#",
    "# ++      ++#",//-->
    "#     <    <#",//<-
    "#    >     >#",// ->
    "#   -      -#",// <--
    "#=====*=====#",
    "#############"
};

int main()
{
    isRunning = true;

    //1st car
    car[0].x =4;
    car[0].y =10;
    car[0].otherx =11;


    while(isRunning)
    {
        system("cls");
        for(int i=0;i<13;i++)
        {
            cout<<map[i]<<endl;
        }
        system("pause>nul");





        if(GetAsyncKeyState(VK_DOWN))
        {
            int y2 = y+1;
            if(map[y2][x]==' ' ||map[y2][x]=='=')
            {
                    map[y][x]=' ';

                y++;
                map[y][x]='*';
            }
        }
          if(GetAsyncKeyState(VK_UP))
        {
            int y2 = y-1;
            if(map[y2][x]==' ' ||map[y2][x]=='=')
            {

            map[y][x]=' ';

                y--;
                map[y][x]='*';
            }
        }
          if(GetAsyncKeyState(VK_RIGHT))
        {
            int x2 = x+1;
            if(map[y][x2]==' ' ||map[y][x2]=='=')
            {
                if(map[y][x2]=='=')
                {
                    map[y][x]='=';
                }
                else
                {
                    map[y][x]=' ';
                }
                x++;
                map[y][x]='*';
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            int x2 = x-1;
            if(map[y][x2]==' ' ||map[y][x2]=='=')
            {
                if(map[y][x2]=='=')
                {
                    map[y][x]='=';
                }
                else
                {
                    map[y][x]=' ';
                }
                x--;
                map[y][x]='*';
            }
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            isRunning =false;
        }

    }


     cout<<map[car[0].y][car[0].otherx]<<"It ran"<<endl;
    return 0;
}

void car1()
{

}
