#include <iostream>
#include <cstring>
#include "PersonalStack.cpp"



bool isLetter(char c)
{
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}


void decompress(MyStack<char>& stack, const char* str, int current) //current в началото е края на стринга
{
    while(current > 0)
    {
        while(isLetter(str[current]))
        {
            stack.push(str[current]);
            //std::cout<<stack.top();
            current--;
        }

        if(str[current] == ')') //когато стигнем до затваряща скоба
        {
            int counter = 0;
            current--;
            while(str[current] != '(') 
            {
                current--;
                counter++;          //докато не стигнем до отваряща скоба
            }
            int multiply = str[current-1] - '0';   //вземаме цифрата пред скобите
            current+=counter; //връщаме се до началото на затварящата скоба

            for(int i =0; i<multiply;i++) //пълним стека multipl пъти
            {
                for(int j = current; j>current - counter;j--) //
                {
                    stack.push(str[j]);
                                   //std::cout<<str[j];
                }
            }

            current -= (counter+2); //Прескачаме отваряща скба и цифра
        }
    }
}

void output(MyStack<char> s)
{
    while(!s.empty())
    {
        std::cout<<s.pop();
    }
}


int main()
{
    char* str = new char[256];
    std::cin.getline(str, 256);
    MyStack<char> s{};
    size_t len = strlen(str);
    decompress(s,str, len-1);
    //std::cout<<"gotov";
    //std::cout<<s.pop();
    output(s);

    delete[] str;
    return 0;
}