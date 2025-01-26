#include <iostream>

int count(int K) //Пресмятя колко цифрено е числото (За K = 1099 - връща 4)
{
    int number = K;
    unsigned counter= 0 ;
    while (number != 0)
    {
         number /= 10;
         counter++;
    } 
    return counter;
} 

bool check (int number)  // Проверява дали едно число е интересно
{
    int prev,current;
    int countNum = count(number);
    bool even, odd;
    for (int t = 1; t<countNum; t++)
       {
            prev = number%10;
            current = (number/10)%10;
            number /= 10;
            even = (current%2 == 0 && prev%2 == 0) ;
            odd = (current%2 != 0 && prev%2 != 0) ;
          if (even || odd) return false;
       }
       return true;
}

void find_sum(int a, int b)   // в интервал [a,b] сумира всички интересни числа
{                        
   bool analyze = false; // проверка за това дали изобщо в интервала има интересни числа
   int sum = 0;
   for (int i = a; i<=b; i++)
   {
       if (check(i))
       {
         if (analyze == false)analyze = true;
         sum += i;
         //std:: cout<<sum<<std::endl; - Проверка
       }
   }
   
   if (analyze==true)
   {
       std::cout<<"The sum of the interesting numbers in the interval is "<< sum;
   }
   else std::cout<<"There are no interesting numbers in the interval." ;
}

int main ()
{
    int a,b;
    do
    {
    std::cout<<"Enter the first number (a)";
    std::cin>>a;
    std::cout<<"Enter the second number (b)";
    std::cin>>b;
    } while (a == b || a > b);
    find_sum(a,b);
}