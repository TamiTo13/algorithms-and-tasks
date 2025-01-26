#include <iostream>

using namespace std;
int main()
{
    int a,b;
    cout<<"Vuvededete intervala ";
    cin>>a>>b;
    bool interesting= false;
    int number = a;
    int last_digit,previous_digit;
    int sum, counter = 0 ;
     for (int i = a; i<=b;i++)
     {
       while (interesting==false || number !=0)
       {
       last_digit = number/10;
       number %= 10;
       previous_digit = number/10;
       if ((previous_digit % 2 == 0 && last_digit % 2 == 0) || (previous_digit%2 == 1 && last_digit%2 == 1) ) // Проверяваме дали става интересно число :)
       {  
          //interesting си остава false;
       }
       else
       {
         interesting = true;
          sum += i;
          counter++;
       }
     }
     }
     cout << sum<< endl << counter ;
     
    return 0 ;
}