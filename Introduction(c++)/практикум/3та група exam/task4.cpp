#include <iostream>

bool sumDigits(int* numbers, int N, int k, int sum, int current)
{ 
    sum += numbers[current];
    if(sum == k) return true;
    if(current >= N) 
    {
        return false;
    }


    bool withNumber = sumDigits(numbers, N, k, sum,current+1);
    bool withoutNumber = sumDigits(numbers, N,k, sum-numbers[current], current+1);

    return withNumber || withoutNumber;



}
     

int main()
{
  int n;
  std::cin >> n;

  int* sequence = new int[n];

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> sequence[i];
  }

  int k;
  std::cin >> k;
    int sum = 0;
  std::cout << sumDigits(sequence, n,k, sum, 0) << std::endl;
  
  delete[] sequence;
  return 0;
}