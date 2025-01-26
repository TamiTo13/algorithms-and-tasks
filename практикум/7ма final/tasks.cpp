#include <iostream>
#include <cstring>


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool out(int currentX,int currentY)
{
    return currentX<0 || currentX>=10 || currentY<0 || currentY>=10;
}

bool recursion(char c[][10], int currentX, int currentY)
{
    if(out(currentX,currentY) || c[currentX][currentY] == '1') return false;
    if(c[currentX][currentY] = 'E') return true;

    for (int i = 0; i < 4; ++i)
    {
        if (recursion(c, currentX + dx[i], currentY + dy[i]))
        {
            return true;
        }
    }

    c[currentX][currentY] = '1';

    return false;
}


int main()
{
    return 0;
}