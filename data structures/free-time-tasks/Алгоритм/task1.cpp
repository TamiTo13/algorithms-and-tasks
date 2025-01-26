#include <iostream>
#include <cmath>


//task 1



size_t task1(int n) //направи го с log 10
{
    size_t counter = 0;
    while(n)
    {
        n /= 10;
        counter++;
    }
    return counter;
}

size_t task1_wrap(int n, int m)
{
    return task1(n*m);
}


//task 2

bool isPrime(int n)
{
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(n%i==0) return true;
    }
    return false;
}

//task 3

void PrimeOut(int n)
{
    for(int i = 2; i<n;++i)
    {
        if(isPrime(i)) std::cout<<i<<" ";
    }
}

//task 4

void Dividers(int n)
{
    for(int i = 2; i<n/2; i++)
    {
        if(n%i == 0 && isPrime(i)) std::cout<<i;
    }
}

//task 5 -рекуrсия

void recursion(int n, size_t step = 0, int rest)
{
    static size_t step = 0;
    if(step == n) std::cout<<n;

    for(int i = 0; i<n-step;i++)
    {
        
    }

}