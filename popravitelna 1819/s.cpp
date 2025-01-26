#include <iostream>

const int dx[8] = {-2, -1, +1, 2, 2, 1, -1, -2};
const int dy[8] = {1 , 2, 2, 1, -1, - 2, -2, -1};

bool out(int x, int y)
{
    return x<0 || y<0 || x>=8 || y>=8;
}

bool check(int x, int y, int preX, int preY)
{
    //std::cout<<preX;
    //std::cout<<" "<<preY<<std::endl;
    //std::cout<<x<<" "<<y;

    if(out(x,y)) return false;
    for(int i = 0; i<8;i++)
    {
        if(preX + dx[i] == x && preY + dy[i] == y) return true;
    }

    std::cout<<"nz";
    return false;
}

bool checkPoints(int* coordinates,int currentX,int currentY, int nextX, int nextY, int size)
{
    if(!check(coordinates[current+2], coordinates[current+3],startX, startY)) return false;
    else if(size = 0) return true;

    current+=2;
    return checkPoints(coordinates,current, coordinates[current], coordinates[current+1], size -1);
}

int main()
{
    int* coordinates = new int[8];
    for(int i = 0; i<8;i++)
    {
        std::cin>>coordinates[i];
    }


    std::cout<<checkPoints(coordinates, 0, 3, 5, 8);
    

    return 0;
}