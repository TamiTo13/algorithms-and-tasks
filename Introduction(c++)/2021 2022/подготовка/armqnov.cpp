#include <iostream>
#include <cmath>
int sumdigits(int n)
{
    if (n == 0)
       return 0;

       return std::abs(n%10 + sumdigits(n/10));
    
}

int main()
{
  unsigned n; std::cin>>n;
  int* numbers = new (std::nothrow) int[n];


  for(int i = 0; i<n; i++)
  {
      std::cin>>numbers[i];
  }
  
  int maxNum = numbers[0];
  for (int i = 1; i<n; i++)
  {
      if (maxNum<numbers[i]) maxNum = numbers[i];
  }
  
  int** arr = new int*[maxNum];
  for(int t = 0; t<maxNum; t++)
  {
      arr[t] = new int*[]
  }

}