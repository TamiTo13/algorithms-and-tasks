#include <iostream>


const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};


bool out(int x, int y)
{
    return x<0 || x>=128 || y<0 || y>=128;
}

bool findRoute(int N[][128], int currentX, int currentY,int volume,bool** path,int finishX, int finishY, int MAX_VOLUME, int startX, int startY)
{

    if(out(currentX, currentY) || path[currentX][currentY] == false) return false;


    volume+=N[currentX][currentY];
    
    if(volume <0 || volume > MAX_VOLUME) 
    {
        volume -=N[currentX][currentY];
        return false;
    }

    path[currentX][currentY] = false;

    if(currentX == finishX && currentY == finishY)
    {
        if(finishX == startX && finishY==startY)
        {
            return true;
        }
        else 
        {
            return findRoute(N, currentX, currentY, volume, path, startX, startY, MAX_VOLUME, startX, startY);
        }
    }

    for(int i = 0; i<4; i++)
    {
        if (findRoute(N, currentX+dx[i], currentY+dy[i], volume, path, finishX,finishY, MAX_VOLUME, startX,startY))
        {
            return true;
        }
    }

    path[currentX][currentY] = true; //backtracking

    return false;
}

void input(int arr[][128], int size)
{
    for(int i=0; i<size;i++)
    {
        for(int j = 0; j<size;j++)
        {
            std::cin>>arr[i][j];
        }
    }
}

int main()
{
    int size;
    std::cin>>size;
    int N[128][128];

    input(N,size);

    bool** path = new bool*[size];
    for(int i = 0; i<size; i++)
    {
        path[i] = new bool[size];
    }

    for(int i = 0; i<size; i++)
    {
        for(int j = 0; j<size; j++)
        {
            path[i][j] = true;
        }
    }

    std::cout<<findRoute(N,0,0,100,path,4,5,150,0,0);

}