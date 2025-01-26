#include <iostream>
#include <cstring>

const int MAX_SIZE = 1024;
const int MAX_WORDS = 128;
const int MAX_LENGTH = 64;


bool isLetter(char x)
{
    return (x >= 'a' && x<= 'z') || (x>= 'A' && x<='Z');
}

int getWords(const char* str, char** getWords)
{
    int counter = 0;
    do
    {
        int wordIndex = 0;
        while(!isLetter(*str)) ++str;

        while(isLetter(*str))
        {
            getWords[counter][wordIndex++] = *str;
            ++str;
        }

        if(wordIndex != 0) 
        {
            getWords[counter++][wordIndex] = '\0';
        }
    } while (*str);

    return counter;
    
}

bool isUnique( char** words, int current, char* word)
{
    for(int i =0; i<current; i++)
    {   
        if(strcmp(words[i], word) == 0) return false;
    }
    return true;
}

int extract(char** words,int counter, char**& newWords)
{
    strcpy(newWords[0], words[0]);
    int current = 1;
    for(int i = 1; i<counter; i++)
    {
        if(isUnique(words, i, words[i]))
        {
            strcpy(newWords[current],words[i]);
            current++;
        }
    }

    return current;
}

int frequencyCounter(char** words, int counter, char* word)
{
    int frequency = 0;
    for(int i = 0; i<counter; i++)
    {
        if(strcmp(word,words[i]) == 0)
        {
            frequency++;
        }
    }
    return frequency;
}

int* Frequency(char** words,int size,  char** newWords, int wordsCount)
{
    int* numbers = new int[wordsCount];

    for(int i = 0; i<wordsCount;i++)
    {
        numbers[i] = frequencyCounter(words, size, newWords[i]);
    }

    return numbers;
}


int main()
{
    char* str = new char[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    char** words = new char*[MAX_WORDS];
    for(int i = 0; i<MAX_WORDS; i++)
    {
        words[i] = new char[MAX_LENGTH];
    }

    
    int wordsCount = getWords(str, words);

    /*for(int i = 0; i<wordsCount;i++)
    {
        std::cout<<std::endl<<words[i];
    } */

    char** NewWords = new char*[MAX_WORDS];
    for(int i = 0; i<MAX_WORDS; i++)
    {
        NewWords[i] = new char[MAX_LENGTH];
    }

    
    int newWordsCount = extract(words, wordsCount,NewWords);
    for(int i = 0; i<newWordsCount;i++)
    {
        std::cout<<std::endl<<NewWords[i];
    }

    int* frequency = Frequency(words, wordsCount, NewWords, newWordsCount);
    for(int i = 0; i<newWordsCount;i++)
    {
        std::cout<<std::endl<<frequency[i];
    }

    std::cout<<newWordsCount;
    for(int i = 0; i<newWordsCount;i++)
    {
        int max = i;
        for(int j = 0; j<newWordsCount; j++)
        {
            if(frequency[j] > frequency[max]) 
            {
                max = j;
            }
        }
        std::cout<<std::endl<<NewWords[max];
        frequency[max] = 0;
    }

    //delete
    return 0;
} 