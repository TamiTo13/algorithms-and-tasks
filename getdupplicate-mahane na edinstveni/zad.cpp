#include <iostream>
#include <cstring>


//To be or not to be - символите които не се повтарят се махат
//T,r,n
bool check(char symbol,int current, const char* str)
{
    if(symbol == ' ') return true;
    for(int i= 0; i<strlen(str);i++)
    {
        if(symbol == str[i] && i != current ) return true;
    }

    return false;
}

int* extract(const char* str)
{
    int counter = 0;
    for(int i = 0; i<strlen(str); i++)
    {
        if(!check(str[i], i, str)) counter++;
    }

    int* positions = new int[counter + 1];
    positions[0] = counter; int t = 1;
    for(int j = 0; j<strlen(str); j++)
    {
        if(!check(str[j], j, str)) 
        {
            positions[t] = j;
            t++;
        }
    }

    return positions;


}

char* getDuplicates(const char* str)
{
    int* positions;
    positions = extract(str);
    char* newStr = new char[(strlen(str) - positions[0]) + 1];\
    int j = 0; int t = 1;
    for(int i = 0; i<strlen(str); i++)
    {
        if(i!=positions[t]) 
        {
            newStr[j] = str[i];
            j++;
        } 
        else t++;
    }

    newStr[strlen(str) - positions[0]] = '\0';
    return newStr;
}


//https://ibb.co/wJ5qwfy - uslovie
int main()
{
    char* a = new char[257];
    std::cin.getline(a, 256);

    char* b;
    b = getDuplicates(a);
    std::cout<<b;

    delete[] b;
}