#include <iostream>
#include <string>
#include "colorful.h"

using namespace std;

const int MAX_X = 12, MAX_Y = 10;
int board[MAX_X][MAX_Y];
string cache = "";

void Print()
{
    string tmp = "";
    tmp += "\n";
    tmp += COLORFUL::bBLACK;
    for (int x = 0; x < MAX_X + 2; x++)
        tmp += "  ";
    tmp += COLORFUL::RESET; tmp += " \n";

    for (int y = 0; y < MAX_Y; y++)
    {
        tmp += COLORFUL::bBLACK; tmp += "  "; tmp += COLORFUL::RESET;
        for (int x = 0; x < MAX_X; x++)
        {
            switch (board[x][y])
            {
            case 0: tmp += COLORFUL::bGRAY; break;
            case 1: case -1: tmp += COLORFUL::bBLUE_l; break;
            case 2: case -2: tmp += COLORFUL::bBLUE; break;
            default: tmp += COLORFUL::bGREEN;
            }
            if (board[x][y] < 0)
            {tmp += "::"; tmp += COLORFUL::RESET;}
            else
            {tmp += "  "; tmp += COLORFUL::RESET;}
        }
        tmp += COLORFUL::bBLACK; tmp += "  "; tmp += COLORFUL::RESET; tmp += " ";
        tmp += "\n";
    }

    tmp += COLORFUL::bBLACK;
    for (int x = 0; x < MAX_X + 2; x++)
        tmp += "  ";
    tmp += COLORFUL::RESET; tmp += " ";
    tmp += "\n";

    if (tmp != cache)
    {
        system("clear");
        cout << tmp;
        cache = tmp;
    }

    system("sleep 0.01");
}

void Fill(int x, int y)
{
    if (board[x][y] != 0)
        return;

    Print();

    board[x][y] = -1;
    if (x > 0)
        Fill(x-1,y);
    if (x < MAX_X - 1)
        Fill(x+1,y);
    if (y > 0)
        Fill(x,y-1);
    if (y < MAX_Y - 1)
        Fill(x,y+1);

    if (board[x][y] < 0)
        board[x][y] = - board[x][y];

    Print();
}

int main()
{
    srand(time(NULL));
    for (int x = 0; x < MAX_X; x++)
        for (int y = 0; y < MAX_Y; y++)
            board[x][y] = (!(x==MAX_X/2&&y==MAX_Y/2))?
                        ((rand()%2)==1?((rand()%2)==1?(2):(0)):(0)):
                        (0);

    Print();
    char ch;
    cin.get(ch);
    if (ch == 'q')
        return 0;

    //board[25][25] = 1;
    Fill(MAX_X/2,MAX_Y/2);

    Print();

    return 0;
}
