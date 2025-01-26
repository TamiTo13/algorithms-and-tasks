//https://github.com/triffon/ip-2021-22/blob/master/practicum/2/extra/tasks.pdf
#include <iostream>

int sumDigits(int n)
{
    if (n==0) return 0;

    return n%10 + sumDigits(n/10);
}

/*int sumDigits(int n) //ABS
{
    return sumDigitsAlg(n>0?n:-n);

} */

void input(int*& a, int n)
{
    a = new int[n];
    for(int i =0; i<n; i++)
    {
        std::cin>>a[i];
    }
}

void output(int* a, int n)
{
    for(int i =0; i<n; i++)
    {
        std::cout<<a[i];
    }
}

int findMax(const int* a, int size)
{
    int max = sumDigits(a[0]);

    for(int i = 1; i<size; i++)
    {
        if(sumDigits(a[i]) >= max) max = sumDigits(a[i]);
    }

    std::cout<<"THE FUCK";
    return max;
}

void printMatrix(const int* const* matrix, int rows, const int* counterCol)
{
    for(int i = 0; i<rows; i++)
    {
        std::cout<<i<<":";
        for(int j = 0;j<counterCol[i];j++)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void deleteMatrix(const int* const* matrix, int rows)
{
    for(int i = 0; i<rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
}

int main()
{
    int size;
    std::cin>>size;
    int* arr;
    input(arr,size);
    output(arr,size);

    int MaxSum = findMax(arr,size);
    std::cout<<"PURVA"<<std::endl;
    int* arrCounter = new (std::nothrow) int[MaxSum];
    if(!arrCounter)
    {
        delete[] arr;
        std::cerr<<"Nqsh mqsto manqk";
        return 1;
    }


    for(int i=0; i<MaxSum; i++) arrCounter[i] = 0; //Nullify

    for(int i=0;i<size; i++)
    {
        ++arrCounter[sumDigits(arr[i])];
    }


    std::cout<<"Vtora"<<std::endl;
    std::cout<<" "<<MaxSum;
    int** matrix = new (std::nothrow) int*[MaxSum];
    if(!matrix)
    {
        delete[] arr;
        delete[] arrCounter;
        std::cerr<<"Yok yer";
        return 2;
    }

    std::cout<<" "<<MaxSum;
    for(int j= 0; j<MaxSum;j++)
    {
        if(arrCounter[j] > 0)
        {
            matrix[j]=new (std::nothrow) int[arrCounter[j]];
            if(!matrix[j])
            {
                //delete matrix - function
                delete[] arr;
                delete[] arrCounter;
                std::cerr<<"Yer kalmadi";
                return 2;
            }
        }
        else matrix[j] = nullptr;
    }

    std::cout<<"TRETA"<<std::endl;
    for(int i=0; i<MaxSum; i++)
    {
        int count =0;
        for(int j=0; j<size;j++ )
        {
            if(arrCounter[i] == 0) continue;
            if(sumDigits(arr[j]) == i) matrix[i][count++] = arr[j];   
        }
    }

    printMatrix(matrix, MaxSum, arrCounter);
    std::cout<<"yeah";
    delete[] arr;
    delete[] arrCounter;
    deleteMatrix(matrix,MaxSum);
    return 0;
}