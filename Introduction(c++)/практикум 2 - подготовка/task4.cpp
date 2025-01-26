#include <iostream>

bool isLetter(char a)
{
    return (a>'a' && a<'z') || (a > 'A' && a < 'Z');
}

int countWords(char* str)
{
    int count = 0;
    while(*str)
    {
        while(isLetter(*str) && *str)
        {
            ++str;
        }
        
        if(*str) count++;

        while(isLetter(*str)) ++str;
    }

    return count;
}



int main()
{
    char str[1024+1];
    std::cin.getline(str, 1024);

}