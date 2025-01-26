#include <iostream>


//dfs algorithm

void input(int a[][100], int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0;j<n;j++)
        {
            std::cin>>a[i][j];
        }
    }
}

bool outOfBounds(int n, int x, int y)
{
    return x<0 || x>=n || y<0 || y>=n;
}

bool pathObserve(int current,int  target)
{
    return current<target && current<10; //DeMorgan
}

bool reachable (int A[][100], unsigned N, int sx, int sy, int target)
{
    if(outOfBounds(N,sx,sy) || !pathObserve(A[sx][sy], target)) return false;

    return A[sx][sy] == target || reachable (A, N, sx, sy + 1, target) || reachable (A, N, sx + 1, sy, target);
}

int main()
{
    int n;
    std::cin>>n;

    int a[100][100];
    
    input(a, n);
    std::cout<<reachable (a, n, 0, 0, 5);
    return 0;

}