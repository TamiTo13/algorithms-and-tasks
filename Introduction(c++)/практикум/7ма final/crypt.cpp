//https://github.com/triffon/ip-2021-22/blob/master/practicum/4/unit7/problems.md

#include <iostream>

char MoveSmall(int offset, char x)
{
    int space = ('z' - 'a') - offset;
    if(x+space>'z')
    {
       return (('a' - 1) + (offset - ('z' - x) )) ;
    }
    else return x+offset;

}

char MoveBig(int offset, char x)
{
    int space = ('Z' - 'A') - offset;
    if(x+space>'Z')
    {
       return (('A' - 1) + (offset - ('Z' - x) )) ;
    }
    else return x+offset;

}


void encrypt(const char str[], int offset, char encryptedStr[])
{
    while(*str)
    {
        if(*str >= 'A' && *str<= 'Z')
        {
            *encryptedStr = MoveBig(offset, *str);
         
        }
        else if(*str >= 'a' && *str<= 'z')
        {
            *encryptedStr = MoveSmall(offset, *str);
        }
        else
        {
            *encryptedStr = *str;
        }

        ++encryptedStr;
        ++str;
    }
    *encryptedStr = '\0';
}

int main()
{

}