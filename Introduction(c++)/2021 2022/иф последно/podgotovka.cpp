#include <iostream>

struct Person {
    int age;
    char* name;
    char* facultyNumber;
    char* adress;
};

void moveWord(char* comparePointer)
{
        while((*comparePointer >= 'a' && *comparePointer <= 'z') || (*comparePointer >= 'A' && *comparePointer <='Z') || (*comparePointer >= '1' && *comparePointer <='9'))
    {
      comparePointer++;
    };
      while(!(*comparePointer >= 'a' && *comparePointer <= 'z') || !(*comparePointer >= 'A' && *comparePointer <='Z') || !(*comparePointer >= '1' && *comparePointer <='9'))
    {
        comparePointer++;
    };
}
/* char* minWord(char* sentence)
{
    char* minPointer = sentence;
    char* comparePointer = sentence;  //сочат към началото

    moveWord(comparePointer);
    while(*comparePointer == '/0')
    {
        if (*comparePointer < *minPointer)
        {
             minPointer = comparePointer;
        }
        moveWord(comparePointer); 
    }
     return minPointer; 
} */

    bool CheckAnagram(char* arrA, char* arrB)
     {
         char newArrA[32];
         char newArrB[32];


     }

int getWords(const char Str[], char words[][32])
{
    int wordCount = 0; int i = 0;
    do
    {
       int wordIndex = 0;
       while(Str[i] && !isspace(Str[i]))
       {
           words[wordCount][wordIndex] = Str[i];
           wordIndex++; i++;
       }
       if(wordIndex != 0)
       {
           words[wordCount][wordIndex] = '\0';
           wordCount++;
       }
    } while (Str[i++]);
    
    return wordCount;
}

int main()
{
    const int maxLEN = 128;
    /* Person dospat;
     Person* p = new Person();
     dospat.age = 22; */

    /* char sentence[64];
     std::cin.getline(sentence, 64);
     std::cout<<sentence;
     std::cout<<minWord(sentence); */

     //char sentence[32];
    // char sentence2[32];

     //std::cin.getline(sentence,32);
     //std::cin.getline(sentence, 32);
    
    //std::cout<<
    //std::cout<< std::boolalpha << CheckAnagram(sentence,sentence2);
    //return 0;

    char str[128];
    std::cin.getline(str, 128);
    char words[maxLEN][32];
    int count = getWords(str, words);
    for(int i = 0; i<count; i++)
    {
        std::cout<<words[i]<<"  ";
    }
}