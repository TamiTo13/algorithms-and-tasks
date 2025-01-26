#include <iostream>

int main()
{
    const int k = 35;
    int x;
    std::cin >> x;
    int fx = x;
    for (int i = 1; i<k; i++)
    {
        if (fx%2==0)
        {
           fx /= 2;
        }
        else
        {
           fx=3*fx+1;
        }
    }
    std::cout<<"For x=  "<<x<<" f(x) is = "<<fx;
    
    return 0;
}