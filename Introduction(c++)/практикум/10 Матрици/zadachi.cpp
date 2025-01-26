  #include <iostream>

    void print(const int* const* arr, int rows, int columns)
    {
        for(int i= 0; i<rows; i++)
        {
            std::cout<<std::endl;
            for(int j = 0; j<columns; j++)
            {
                std::cout<<arr[i][j]<<" ";
            }
        }
    }

    void initialize(int** arr, int rows, int columns)
    {
        for(int i= 0; i<rows; i++)
        {
            for(int j = 0; j<columns; j++)
            {
                std::cin>>arr[i][j];
            }
        }
    }

    void clear(int **& arr, int N)
    {
        for(int i= 0; i<N; i++)
        {
            delete[] arr[i];
        }

        delete arr;
        arr = nullptr;
    }

    int sumDiagonal(const int* const* arr, int rows)
    {
        int sum = 0;
        for(int i = 1; i<rows; i++)
        {
            sum+= arr[i][i-1]; //i,i = glaven
        }

        return sum;
    }

    int Multiply(const int* const* arr, int rows)
    {
        int sum = 1;
        for(int i = 0; i<rows; i++)
        {
            sum = sum * arr[i][i+1];
        }

        return sum;
    }

    void printTrans(const int* const * arr, int N, int M)
    {
        for(int i = 0; i<M; i++)
        {
            std::cout<<std::endl;
            for(int j = 0; j<N; j++)
            {
                std::cout<<arr[j][i]<<" ";
            }
        }
    }

  int main()
  {
    int N,M;
    std::cin>>N>>M;

    int** matrix = new int*[N];

    for(int i = 0; i<N; i++)
    {
        matrix[i] = new int[M];
    }
    initialize(matrix, N, M);

    print(matrix, N, M);

    printTrans(matrix, N, M);

    std::cout<<"Otgovor: "<<sumDiagonal(matrix,N);

    clear(matrix,N);

    return 0;
  }