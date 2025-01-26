#include <iostream>

//Да се напише рекурсивна функция, която намира произведението от цифрите на дадено естествено число.

int recursionRec(int n)
{
    if(n == 0) return 1;

    return n%10*(recursion(n/10));
}

int recursion(int n)
{
     return n == 0? 0 : recursionRec(n); 
}


int main()
{

}