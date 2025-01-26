#include <iostream>

const int dx[4] = {1, 0, -1,0};
const int dy[4] = {0, 1, 0, -1};

const int diagX[4] = {1, -1, -1, 1};
const int diagY[4] = {1, 1, -1, -1};
bool out(int positionX, int positionY, int n)
{
    return positionX<0 || positionX>=n || positionY <0 || positionY >=n;
}

/*bool trackingLine(bool** table, int n, int positionX,int positionY, bool** path)
{
    if(table[positionX][positionY] == true || path[positionX][positionY] == true) return false;
    if( out(positionX,positionY, n) ) return true;

    path[positionX][positionY] == true;
    for(int i = 0; i<4; i++)
    {
        if( !trackingLine(table,n,positionX+dx[i], positionY+dy[i],path ) ) // ! - DeMorgan
        {
            path[positionX][positionY] = false;
            return false;
        }
    }

    for(int i = 0; i<4; i++)
    {
        if( !trackingLine(table,n,positionX+diagX[i], positionY+diagY[i],path ) ) // ! - DeMorgan
        {
            path[positionX][positionY] = false;
            return false;
        }
    }

    return true;
} */

bool check(bool** table, int n, int positionX,int positionY)
{
    int currentX = positionX;
    int currentY = positionY;
 
    for(int i = 0; i<4; i++)
    {
        while(!out(positionX,positionY,n) )
        {
            currentX+=dx[i];
            currentY+=dy[i];
            if(table[positionX][positionY] == true) return false;
        }        
    }

    currentX = positionX;
    currentY = positionY;
    for(int i = 0; i<4; i++)
    {
        while(!out(positionX,positionY,n) )
        {
            currentX+=diagX[i];
            currentY+=diagY[i];
            if(table[positionX][positionY] == true) return false;
        }        
    }

    return true;
}


bool recursion(bool** table, int positionY, int n)
{
    if(positionY >= n) return true;

    for(int i = 0; i<n ; i++)
    {
        if(check(table,n,i,positionY))
        {
            table[i][positionY] = true;
        
            
            if(check(table,n, i, positionY+1))
            {
                return true;
            }

            table[i][positionY] = false;
        }
    }

    return false;
}

void printSolution(bool** board, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << " " << board[i][j] << " ";
        printf("\n");
    }
}

void input(bool** arr, int size)
{
    for(int i = 0; i<size;i++)
    {
        for(int j =0; j<size;j++)
        {
            std::cin>>arr[i][j];
        }
    }
}

int main()
{
    bool** table = new bool*[4];
    for(int i = 0; i<4;i++)
    {
        table[i] = new bool[4];
    }

    input(table, 4);
  
    if (recursion(table,0,0,4,0 ) == false) {
        std::cout << "Solution does not exist";
        return false;
    }
  
    printSolution(table, 4);
    return 0;
}
  