#include <iostream>

void cleanMatrix(int**& matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;
    matrix = nullptr;
}

int sumDigits(int n)
{
    if (n == 0)
    {
        return n;
    }
        return n%10 + sumDigits(n/10);
}


int main()
{
    int n; std::cin>>n;
    std::cout<<sumDigits(n);

    int N; std::cin>>N;
    int* arr = new int[N-1];
    if (!arr)
    {
        std::cout<<'\n'<<"no memory";
         return 1;
    }
    for(int p = 0; p<N; p++)
    {
        std::cin>>arr[p];
    }

    int Max = sumDigits(arr[0]);
    int Curr;
    for(int i = 1; i<N; i++)
    {
        Curr = sumDigits[arr[i]];
        if (sumDigits(arr[i]) > Max)  Max = sumDigits(arr[i]);
    }
    
    int* columns = new (std::nothrow) int[Max-1];
    if (!columns)
    {
        delete[] arr; std::cout<<"no memory";
    }

    for (int t = 0; t<Max; t++)
    {
        columns[t] = 0;
    }

    for (int t = 0; t<Max; t++)
    {
        ++columns[sumDigits(arr[t])];
    }

    int** matrix = new (std::nothrow) int* [Max-1];
    if (!matrix)
    {
        delete[] columns; delete[] arr;
        std::cout<<"no memory";
        return 2;
    }

    for(int i=0;i<Max; i++)
    {
        if (columns[i] > 0)
        {
        *matrix = new (std::nothrow) int[columns[i]]; 
        if (!matrix[i])
            {
                // Don't forget to delete all previously allocated memory!
                cleanMatrix(matrix, i);
                delete[] arr;
                delete[] columns;
                std::cerr << "Not enough memory!\n";
                return 2;
            }
        }
        else
        {
            matrix[i] = nullptr;
        }
    }

    for(int i = 0; i<N; i++)
    {
        int currSum = sumDigits( arr[ i ] );
        int innerIndex = columns[ currSum ] - 1;
        columns[ currSum ]--;
        matrix[ currSum ][ innerIndex ] = arr[ i ];
    }

    for (int i = 0;i<Max; i++)
    {
        std::cout<<i<<":";
        for(int j = 0; j<columns[i]; i++)
        {
          std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<'\n';
    }

   return 0;
}