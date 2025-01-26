#pragma once
#include "PersonalStack.h"
#include <cstring>


 
class RacketStack //:public MyStack<char>
{
    MyStack<char> s;
    public:
    void input(const char*);
    bool check(const char* ) ;
    bool isPair(char) const;

    friend bool isOpeningBracket(char a) ;
    friend bool isClosingBracket(char b);

};

bool isOpeningBracket(char a)  
{
    return a == '(' || a == '{' || a == '[';
}

bool isClosingBracket(char a) 
{
     return a == ')' || a == '}' || a == ']';
}

bool RacketStack::isPair(char c) const
{
    return s.top() == '(' && c == ')' 
            || s.top() == '{' && c == '}'
            || s.top() == '{' && c == '}' ;
}

bool RacketStack::check(const char* str)
{
    for(int i = strlen(str) - 1; i>=0; i--)
    {
        if(isOpeningBracket(str[i])) s.push(str[i]);

        else if(isClosingBracket(str[i]) && !(s.empty())) 
        {
            if (isPair(str[i])) s.pop();
            else return false;
        }
        else return false; // Ако започнем със затваряща скоба
    }

    return s.empty(); //ако след извършване на цикъла, стекът е празен връща 1
}
