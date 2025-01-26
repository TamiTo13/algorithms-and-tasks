#include <iostream>
#include <cstring>

void sort(char**& str, int words)
{
    for(int i = 0; i<words - 2; i++)
    {
        int min = i;
        for(int j = i+1; j< words - 1; j++)
        {
            if(strcmp(str[min], str[j]) < 0) min = j;
        }
        if(min != i)std::swap(str[i], str[min]);
    }
}

bool compare(const char* str, const char* word)
{
    for(int i =0; i<strlen(word); i++)
    {
        if( *str != word[i]) return false;
        str++;
    }
    return true;
}

/* bool SwapWords(const char* str, const char* word1, const char* word2)
{

    while(*str && counter != 0 )
    {
        if( *str == word[0])
        { 
            if(compare( str, word1))
            {
                counter--;
                
            }
        }
        str++;
    }
    return counter;
} */

int countWord(const char* str, const char* word)
{
    int counter = 0;
    while(*str)
    {
        if( *str == word[0])
        { 
            if(compare( str, word))
            {
                counter++;
                str +=strlen(word);
            }
        }
        str++;
    }
    return counter;
}

int newSize(const char* str, const char* word1, const char* word2)
{
    int asymetry = strlen(word2) - strlen(word1);
    asymetry *= countWord(str, word1);
    if(strlen(str) + asymetry <= 0 ) return 0;
    return strlen(str) + asymetry;
}

char* newArr(const char* str, const char* word1, const char* word2)
{
    int newsize = newSize(str,  word1, word2);
    char* newArray = new (std::nothrow) char[newsize];

    int count = countWord(str, word1);
    int counter = 0;
    while(*str )
    {
        if( *str == word1[0] && count != 0)
        { 
            
            if(compare( str, word1))
            {
                count--;
                for(int i = 0;i<strlen(word2); i++)
                {
                    newArray[counter++] = word2[i];
                }
                str += strlen(word1);
            }
        }
        newArray[counter++] = *str;
        ++str;
    }
    
    newArray[counter] = '\0';
    return newArray;
}


int main()
{
    char* str = new char[129];
    std::cin.getline(str, 128);
    char* newStr = newArr(str, "kur" , "kurr");
    std::cout<<newStr;

    delete[] str;
    delete[] newStr;
    return 0;
}