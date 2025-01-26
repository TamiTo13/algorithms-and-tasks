#include <iostream>
#include <vector>


bool isEven(int a)
{
    return a % 2 == 0;
}

std::vector<int> filter(std::vector<int> arr, bool (*function)(int))
{
    std::vector<int> NewArr;
    std::vector<int>::iterator ptr = arr.begin();

    while(ptr != arr.end())
    {
        if( function(*ptr) ) NewArr.push_back(*ptr);
        ptr++;
    }

    for(int i = 0; i<NewArr.size(); i++)
    {
        std::cout<<" "<<NewArr[i];
    }
}

int main()
{
    std::vector<int> arr = {1,5,6,2,0};
    filter(arr, isEven);

}