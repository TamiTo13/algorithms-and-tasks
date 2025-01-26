#include <iostream>
#include <cstring>
#include "PersonalStack.h"

//PUSH POP

int main()
{
    char* str = new char[256];
    std::cin.getline(str, 256);
    MyStack<char> s;

    for(int i = 0; i<strlen(str);i++)
    {
        s.push(str[i]);
    }

    for(int i = 0; i<strlen(str);i++)
    {
        std::cout<<s.pop();
    }

    delete[] str;
    return 0;
}