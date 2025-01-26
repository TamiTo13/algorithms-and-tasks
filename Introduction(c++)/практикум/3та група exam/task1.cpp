#include <iostream>

int sumDividers(int n)
{
    int sum = 0;
    for(int i = 1; i<=n/2; i++)
    {
        if(n%i == 0) sum+=i;
    }

    return sum;
}

bool isDone(int n)
{
    return n==sumDividers(n) - 2;
}

int ABS(int a)
{
    return a >= 0? a: -a;
}

bool checkDigit(int a, int b, int N)
{
    if(N == a || N == b) return false;

    int check = N;

    while(check<b)
    {
        if(isDone(check))
        {
            if(ABS(N-check) < ABS(N-a) || ABS(N-check) < ABS(N-b)) return true;
        }
            ++check;
    }

    check = N;

    while(check>a)
    {
        if(isDone(check))
        {
            if(ABS(N-check) < ABS(N-a) && ABS(N-check) < ABS(N-b)) return true;
        }
            --check;
    }

    return false;

}

int sumAlmostDone(int a, int b)
{
    int sum = 0;
    for(int i=a; i<b; i++)
    {
        if(checkDigit(a,b,i)) sum +=i;
    }

    return sum;
}

int main()
{
         int a, b;
  std::cin >> a >> b;

  std::cout << sumAlmostDone(a, b) << std::endl;

  return 0;
}