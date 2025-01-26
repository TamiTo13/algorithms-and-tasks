#include <iostream>


//https://github.com/triffon/ip-2021-22/blob/master/practicum/2/14-algorithms/14-tasks.pdf

//task 1
int findIndex(int* arr,int size, int a)
{
    int index = -1;
    for(int i = 0; i<size; i++)
    {
        if(arr[i] == a) index = i; 
    }
    
    return index;
}

//task 2

void input(int*& arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        std::cin>>arr[i];
    }
}

int countEven(int* arr, size_t size)
{
    int count = 0;
    for(int i = 0; i< size; i++)
    {
        if(arr[i]%2 == 0) count++; 
    }

    return count;
}

int sumEvens(int* arr, int current)
{
    int sum = 0;
    for(int i = 0; i<current; i++)
    {
        if(arr[i] % 2 != 0) sum +=arr[i];
    }

    return sum;
}


void print(const int* arr, int size)
{
    std::cout<<std::endl;
    for(int i = 0; i< size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

void task2()
{
    int size;
    std::cin>>size;
    
    int* arr = new (std::nothrow) int[size];
    if(!arr)
    {
        std::cerr<<"No memory";
        return ;
    }

    input(arr, size);
    std::cout<<"  "<<countEven(arr,size);
    //print(arr, size);
    /* int* ToImport;
    ToImport = buffer(arr, size); */

    int* result= new  (std::nothrow) int[size + countEven(arr, size)];
    if(!result)
    {
        delete[] arr;
        std::cerr<<"memo";
        return ;
    }

    int resultCounter = 0;
    for(int i = 0;i<size; i++)
    {
        result[resultCounter++] = arr[i] ;
        if(arr[i] % 2 == 0)
        {
            result[resultCounter++] = sumEvens(result, resultCounter);
        }
    }
    print(result, size + countEven(arr, size));


    delete[] result;
    delete[] arr;
}


//task 3-------------------------------------

void selectionSor(int* arr, int size) //nizhodqsht
{
    for(int i = 0; i<size; i++)
    {
        int Max = i;
        for(int j = i + 1; j<size;j++)
        {
            if(arr[j] > arr[i]) Max = j;
        }
        if(Max != i) std::swap(arr[i],arr[Max]);
    }
}

//task 5--------------------------------------

const short MAX_VALUE = 100;
const short MAX_SIZE = 1024;

int findMax(short arr[],int size);

void sortByFrequency(short arr[], int size)
{
    short frequency[MAX_VALUE+1] = {};

    for(int i = 0; i<size; i++)
    {
        frequency[arr[i]] ++;
    }

    int counter = 0;
    while(counter<size)
    {
        int max = findMax(frequency, MAX_VALUE+1);

        for(int i=0; i<frequency[max]; i++)
            arr[counter++] =  max;

        frequency[max] = 0;
    }

}

int findMax(short arr[], int size)
{
    int max = 0;
    for(int j = 0; j<size; j++)
    {
        if(arr[max] < arr[j]) max = j;
    }

    return max;
}

void print(const short* const arr, int size)
{
    for(int i = 0; i<size; i++)
        std::cout<<arr[i]<<" ";
}

void task5()
{
    int size;
    std::cin>>size;
    short arr[size];
    for(int i = 0;i<size; i++)
    {
        std::cin>>arr[i]; 
    }

    print(arr,size);
    sortByFrequency(arr,size);
    print(arr,size);
    return ;
}


//task 6 ------------------------------

int guess(int low, int high)
{
    char answer;
    int mid = low + (high - low) / 2;

    do
    {
        std::cout<<mid<<" ?";
        std::cin>>answer;
    } while (answer != 'y' && answer != 'u' && answer !='d');
    
    switch(answer) {
    case 'y' : 
        return mid;
        break;
    case 'u' : 
        return guess(mid, high);
        break;
    case 'd' : 
        return guess(low, mid);
        break;
    }
}

int main()
{
    int low, high;
    std::cin>>low;
    std::cin>>high;
    guess(low,high);
    return 0;
}