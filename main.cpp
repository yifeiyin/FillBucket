#include <iostream>
#include "colorful.h"

using namespace std;

const int MAX_X = 50, MAX_Y = 50;
int board[MAX_X][MAX_Y];

void Print()
{
    system("clear");
    cout << endl;
    cout << COLORFUL::bBLACK;
    for (int x = 0; x < MAX_X + 2; x++)
        cout << "  ";
    cout << COLORFUL::RESET;

    for (int y = 0; y < MAX_Y; y++)
    {
        cout << COLORFUL::bBLACK << "  " << COLORFUL::RESET;
        for (int x = 0; x < MAX_X; x++)
        {
            switch (board[x][y])
            {
            case 0: cout << COLORFUL::bGRAY; break;
            case 1: cout << COLORFUL::bBLUE_l; break;
            case 2: cout << COLORFUL::bBLUE; break;
            default: cout << COLORFUL::bGREEN;
            }
            cout << "  " << COLORFUL::RESET;
        }
        cout << COLORFUL::bBLACK << "  " << COLORFUL::RESET;
        cout << endl;
    }

    cout << COLORFUL::bBLACK;
    for (int x = 0; x < MAX_X + 2; x++)
        cout << "  ";
    cout << COLORFUL::RESET;
    cout << endl;

    system("sleep 0.01");
}

void Fill(int x, int y)
{
    if (board[x][y] != 0)
        return;

    cout << x << ", " << y << endl;
    Print();

    board[x][y] = 1;
    if (x > 0)
        Fill(x-1,y);
    if (x < MAX_X - 1)
        Fill(x+1,y);
    if (y > 0)
        Fill(x,y-1);
    if (y < MAX_Y - 1)
        Fill(x,y+1);
}

int main()
{
    for (int x = 0; x < MAX_X; x++)
        for (int y = 0; y < MAX_Y; y++)
            board[x][y] = (rand()%2)==1?((rand()%2)==1?(2):(0)):(0);

    board[8][8] = board[7][8] = board[6][8] =
            board[8][6] = board[8][7] = board[8][8] = 2;

    Print();

    cin.get();

    Fill(25,25);



    Print();

    return 0;
}
