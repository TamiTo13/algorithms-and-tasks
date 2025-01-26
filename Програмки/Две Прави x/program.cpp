#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int delimo,delitel;
    std::cout<<"Въведи делимото.";
    std::cin>>delimo;
    std::cout<<"Въведи степента на двойката.";
    std::cin>>delitel;
    if (delimo & (1 << delitel) - 1)) == 0) 
    {
        cout<<"True";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}