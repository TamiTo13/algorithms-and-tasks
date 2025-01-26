#include <iostream>
#include <stack>


//Tower of Hanoi


void recursion(int n, std::stack<int> A,std::stack<int> B, std::stack<int> C)
{
    if(n == 0) return;

    recursion(n-1, A,B,C);
    C.push(A.top());
    A.pop();
    recursion(n-1, B, A, C);

}