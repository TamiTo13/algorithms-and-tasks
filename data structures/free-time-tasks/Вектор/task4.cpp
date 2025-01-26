#include <iostream>
#include <vector>

template <typename T>
void someFunction(std::vector<int> arr, T func)
{
   for(int& elem: arr)
   {
        func(elem);
   }
}


int main()
{

}