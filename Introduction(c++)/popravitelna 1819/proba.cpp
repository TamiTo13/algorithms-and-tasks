#include <iostream>

int main()
{
    int* arr;
    std::cout<<sizeof(int*);
    std::cout<<std::endl;

    int arr2[4] = {0,1,2,3};
    std::cout<<sizeof(arr2);
    std::cout<<std::endl;

    arr =arr2;
    std::cout<<sizeof(int*);
    std::cout<<std::endl;


    for(int i = 0; i<sizeof(arr); i++)
    {
        std::cout<<arr[i];
    }
}