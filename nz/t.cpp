#include <iostream>
#include <cstring>

void toBinary(int n)
{
    if (n == 0) 
    {
        return;
    }

    toBinary(n / 2);
    std::cout << n % 2;
}

double calculate(unsigned n)
{
    if (n == 1)
    {
        return 1;
    }

    return calculate(n-1) + 1/(n*n);
}

int sum(unsigned n)
{
    if (n < 10)
    {
        return n%10;
    }

    return n %10 + (sum(n/10));
}

/* int fact(unsigned n)
{
    if(n == 1)
    {
        return 1;
    }

    //std::cout<<n;
    return (n)*fact(n-1);
} */

int fact(int n) {   //Task 5.
	if (n == 0) {
		return 1;
	}
    std::cout<<n;
	return fact(n - 1) * n;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void revArr(int* arr, int one, int two)
{
    if(one>two)
        return;

    swap(arr[one], arr[two]);

    return revArr(arr, one+1, two-1);
}

void print(int* arr)
{
    //std::cout<<sizeof(arr);
    for(int i = 0; i<=sizeof(arr); i++)
    {
        std::cout<<arr[i];
    }
}

bool palindrom(char* str, int start, int end)
{
    if (start >= end) return false;
    
    if(str[start] != str[end]) return false;

    if(start<=end) return palindrom(str, start+1, end-1);

    return true;
}

bool isPalindromeRec(char* str, int l, int r)
{
    if (l >= r)
    {
        return true;
    }

    if (str[l] != str[r])
    {
        return false;
    }

    if (l < r )
    {
        return isPalindromeRec(str, l + 1, r - 1);
    }

}

int findNOD(int one, int two)
{
    if(two == 0)
    return one;

    return findNOD(two, one%two);
}

int main() {
    
    char str[] = "abba";
    std::cout<<strlen(str);
    std::cout<<isPalindromeRec(str, 0, strlen(str)-1);
}

