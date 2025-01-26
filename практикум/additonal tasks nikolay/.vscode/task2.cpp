#include <iostream>

//const int dx[4] = {1,0,-1,0};
//const int dy[4] = {0,1,0,-1}; for alternative solution


bool out(int x, int y, int m, int n)
{
    return x<0 || x>=m || y<0 || y>=n;
}

bool recursion(int prevX,int prevY,int currentX, int currentY, int finishX,int finishY, int add, int** Matrix, int m, int n, bool** visited)
{
    if(out(currentX,currentY,m,n) || Matrix[prevX][prevY] + add != Matrix[currentX][currentY] || visited[currentX][currentY] == true) return false;

    if(currentX == finishX && currentY == finishY) return true;

    visited[currentX][currentY] = true;

    bool up =recursion(currentX,currentY, currentX+1,currentY,finishX,finishY,add,Matrix,m,n, visited);

    bool down =recursion(currentX,currentY, currentX-1,currentY,finishX,finishY,add,Matrix,m,n, visited);

    bool right =recursion(currentX,currentY, currentX,currentY+1,finishX,finishY,add,Matrix,m,n, visited);

    bool left =recursion(currentX,currentY, currentX,currentY-1,finishX,finishY,add,Matrix,m,n, visited); 

    if(up||down||right||left) return true;

    visited[currentX][currentY] = false;

    return false;
}

bool recursionWrap(int startX,int startY, int finishX,int finishY, int** Matrix, int m, int n)
{
    bool** visited = new bool*[m];
    for(int i = 0; i<n;i++)
    {
        visited[i] = new bool[n];
    }

    visited = {0,};
    //UP
    int add = Matrix[startX][startY] + Matrix[startX+1][startY];
    bool upCase = recursion(startX, startY, startX+1, startY, finishX, finishY,add, Matrix,m,n,visited );

    //DOWN
    add = Matrix[startX][startY] + Matrix[startX-1][startY];
    bool downCase = recursion(startX, startY, startX-1, startY, finishX, finishY,add, Matrix,m,n,visited);

    //RIGHT
    add = Matrix[startX][startY] + Matrix[startX][startY+1];
    bool rightCase = recursion(startX, startY, startX, startY+1, finishX, finishY,add, Matrix,m,n, visited);

    //LEFT
    add = Matrix[startX][startY] + Matrix[startX][startY-1];
    bool leftCase = recursion(startX, startY, startX, startY-1, finishX, finishY,add, Matrix,m,n,visited);

    return upCase || downCase || rightCase || leftCase;
}

void input(int** arr, int n, int m)
{
    for(int i = 0; i<m;i++)
    {
        for(int j =0; j<n;j++)
        {
            std::cin>>arr[i][j];
        }
    }
}

int main()
{
     int m;
    do
    {
    std::cin>>m;
    } while (m < 2 || m>20);
    

    int n;
    do
    {
    std::cin>>n;
    } while (n< 2 || n>20); //demorgan

    int** arr = new int*[m];
    for(int i = 0; i<n;i++)
    {
        arr[i] = new int[n];
    }

    input(arr, n,m);
    std::cout<<recursionWrap(0,1, 2, 5,arr, m, n);
}