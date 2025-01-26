#include <iostream>

const int dx[8] = {-2, -2, -1, +1, 2, 2, -1, 1};
const int dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};


bool out(int n, int x, int y)
{
    return x<0 || y<0 || x>=n || y>=n;
}

bool fillMatrix(int** matrix,int n, int currentX, int currentY, bool** path, int& counter)
{
    if(out(n,currentX,currentY) || path[currentX][currentY] == false) return false;

    
    matrix[currentX][currentY] = counter;
    path[currentX][currentY] = false;
    counter++;

    if(counter == n*n) return true;

    for(int i = 0; i<8;i++)
    {
        if(fillMatrix(matrix, n, currentX + dx[i], currentY+dy[i], path, counter) )
        {
            return true;
        }
    }

    matrix[currentX][currentY] = 0;
    counter--;
    path[currentX][currentY] = true;

    return false;
}

void print(int** arr, int n)
{
    for(int i = 0; i<n;i++)
    {
        std::cout<<std::endl;
        for(int j=0;j<n;j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
    }
}

int main()
{
    int n;
    std::cin>>n;

    int** arr= new int*[n];
    for(int i = 0;i<n;i++)
    {
        arr[i] = new int[n];
    }

    for(int i = 0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = 0;
        }
    }
    //print(arr, n);

    bool** path= new bool*[n];
    for(int i = 0;i<n;i++)
    {
        path[i] = new bool[n];
    }

    for(int i = 0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            path[i][j] = true;
        }
    }

    int counter = 0;
    fillMatrix(arr, n, 0,0,path, counter);
    print(arr,n);

    for(int i = 0; i<n;i++)
    {
        delete[] arr[i];
    }

    delete arr; arr = nullptr;

    for(int i = 0; i<n;i++)
    {
        delete[] path[i];
    }

    delete path; path = nullptr;

    return 0;
}
