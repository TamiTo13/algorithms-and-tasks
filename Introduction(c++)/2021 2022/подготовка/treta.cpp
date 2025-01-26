#include <iostream>


bool solve(int number1,int number2)
{
    if(number1>number2)
        return isSubNumber(number1, number2);

    return isSubNumber(number2, number1);
}

bool isSubNumber(int bigger, int smaller)
{
    if (smaller == bigger || smaller ==0)
        return true;

    if(bigger ==0)
        return false;
    int biggerDigit = bigger%10;
    int smallerDigit = smaller % 10;

    if (biggerDigit == smallerDigit)
        return isSubNumber (bigger/10, smaller/10);
    return isSubNumber (bigger/10, smaller);
}

int vtora()
{
    int countRoots; std::cin>>countRoots;
    int* K = new (std::nothrow) int[countRoots];
    if (!K)
    {
        std::cout<<"no memory";
        return 1;
    }

    for (int i=0; i<countRoots; i++)
    std::cin>>K[i];
}
int main()
{
    
}