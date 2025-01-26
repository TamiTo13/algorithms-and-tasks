#include <iostream>

const int dx[8] = {-2, -1, +1, 2, 2, 1, -1, -2};
const int dy[8] = {1 , 2, 2, 1, -1, - 2, -2, -1};

bool out(int x, int y)
{
    return x<0 || x>7 || y<0 || y>7;
}

bool check(int x, int y, int preX, int preY)
{
    if(out(x,y)) return false;

    for(int i = 0;i <8;i++)
    {
        if(preX + dx[i] == x && preY + dy[i] == y) return true;
    }

    return false;
}

bool checkPoints(int* coordinates, int size)
{
    for(int i = 0; i<size; i+=2)
    {
        if(!check(coordinates[i], coordinates[i+1], coordinates[i+2], coordinates[i+3]) )
        {
            return false;
        }
    }

    return true;
}

int getSequence(int* coordinates, int size)
{
    int current = 0;
    int max,currMax = 0;
    int maxIndex;
    while(current <= size)
    {
        while( check(coordinates[current], coordinates[current+1], coordinates[current+2],coordinates[current+2]) )
        {
            current +=2;
            currMax++;
            if(current == size) break;
        }
        current += 2;

        if(max<currMax)
        {
            max = currMax;
            maxIndex = (current-2) - currMax;
        } 
        currMax = 0;
    }

    for(int j = 0; j<max; j++)
    {
        std::cout<<coordinates[maxIndex++]<<" "<<coordinates[maxIndex++]<<std::endl;
    }

    return max;
}

int main()
{

    
    int positions;
    do
    {
         std::cin>>positions;
    } while (positions<=0 || positions >1000);
    
    positions <<= 1; //multiply by two

    int* coordinates = new int [positions];

    for(int i = 0; i<positions; )
    {
        //std::cout<<i<<std::endl;
        std::cin>>coordinates[i++];
        //std::cin>>coordinates[i++];
    } 

    //std::cout<<checkPoints(coordinates, positions/2);
    int max = getSequence(coordinates, positions);

}