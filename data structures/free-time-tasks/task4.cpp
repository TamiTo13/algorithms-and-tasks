#include <iostream>
#include <stack>

//СОРТИРАЙТЕ СТЕК - без използване на масиви


std::stack<int> Sort(std::stack<int> first)
{
    std::stack<int> second;
    int buffer;
    while(!first.empty())   //като изпразним първия контейнер, значи сортировката е приключила 
    {
        buffer = first.top();   //вадим това най-горе на първия
        first.pop();               //


        // v ако сме взели всичко значи си отива най отдолу
        while(!second.empty() && buffer > second.top())  //<-условието
        {
            //std::cout<<"TEST";
            first.push(second.top());  //връщаме го в първия(после ги връщаме, щото не влизаме в while-а)
            second.pop();
        }

        second.push(buffer); //слагаме елемента
    }

    return second; //накрая връщаме втория контейнер
}

int main()
{
    std::stack<int> s;
    int current;
    for(int i = 0; i<5;i++)
    {
        std::cin>>current;
        s.push(current);
    }

    std::stack<int> s1 = Sort(s);
    while(!s1.empty())
    {
        std::cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}