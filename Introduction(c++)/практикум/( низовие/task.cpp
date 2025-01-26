#include <iostream>
#include <cstring>

bool palindrom(char* str)
{
    int j = strlen(str) - 1;
    for(int i = 0; i<strlen(str)/2 ; i++)
    {
        if(str[i] != str[j]) return false;
        j--;

    }
    return true;
}

bool isDigit(char str)
{
    return (str >= '0' && str<='9');
}

void Atoi(const char* str)
{
    
    while(!isDigit(*str) && *str == '0') ++str;

    while(*str)
    {
        while(!isDigit(*str) && *str ) 
        {
            ++str;
        }

        std::cout<<*str;
        ++str;
    }
}

bool isUpper(char letter)
{
    return letter>= 'A' && letter<='Z';
}

bool isLetter(char letter)
{
    return (letter>= 'A' && letter<='Z') || (letter>= 'a' && letter<='z');
}
void Upper(char* str)
{
    while(*str)
    {
        if(isspace(*str))
        {
            while(isspace(*str)) ++str;
            if(!isUpper(*str) && isLetter(*str)) *str += ('A' - 'a'); 
        }
        ++str;
    }

    std::cout<<std::endl<<str;

}

char** getWords(const char* str)
{
    int i =0;
    while(isspace(str[i])) ++str;

    int counter = 1;
    while(str[i])
    {
        counter++;
        i++;
    }
}
int main()
{
    char* a  = new char[129];
    std::cin.getline(a, 128);

    Upper(a);
    std::cout<<a;
}