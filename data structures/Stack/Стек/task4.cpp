#include <iostream>
#include <cstring>
#include <vector>
#include "PersonalStack.cpp"



bool isLetter(char c)
{
    return c>='A' && c<='Z';
}

bool isNumber(char c)
{
    return c>= '0' && c<='9';
}


//За задачата съм приел,че низът е коректен
/*bool invalid(char c) //ако е невалиден output
{
    return (c<'a' || c>'z') && (c <'A' ||  c>'Z')  && !isNumber(c);
} */


bool input(MyStack<char>& stack, const char* str)
{   
    int i = strlen(str) - 1;

    while( i >= 0)
    {
        
        while(!isNumber(str[i]) && i >= 0)
        {
            stack.push(str[i]);
            i--;
        }

        if(i>0) 
        {
            stack.pop(); //махаме отваряща скоба

            int multiply = str[i] - '0'; //вземаме цифрата
            std::vector<char> buffer; //пълним буфера със стойността, която ще наслагваме

            while(!stack.top() == ')')
            {
                buffer.push_back(stack.top());
                stack.pop();
            }

            std::vector<char>::iterator ptr;

            for(int i = 0; i<multiply; i++)
            {
                ptr = buffer.begin();

                while(ptr != buffer.end())
                {
                    std::cout<<i<<std::endl;
                    stack.push(*ptr);
                    ptr++;
                }
            }

            if(i>0) i--; // продължаваме към началото, прескачайки цифрата
        }
    }
}

void output(MyStack<char> s)
{
    while(!s.empty())
    {
        if(s.top() == ')') s.pop();
        else
        {
            std::cout<<s.pop();
        }
    }
}


int main()
{
    char* str = new char[256];
    std::cin.getline(str, 256);
    MyStack<char> s{};
    input(s,str);
    
    //std::cout<<s.pop();
    output(s);

    delete[] str;
    return 0;
}