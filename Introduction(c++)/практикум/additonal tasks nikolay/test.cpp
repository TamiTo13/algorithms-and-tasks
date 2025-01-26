#include <iostream>

using namespace std;

void f(int * arr1, const int * arr2)
{
	int * p1 = arr1;
	const int  *p2 = arr2;
	
	while(*p2 >= 0)
	{
        
		*p1++ = *p2++;
        std::cout<<*p1<<" "<<*p2<<std::endl;
	}
    	

}

int main()
{
    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};
    
    f(A, B);
    return 0;
}