#include <iostream>
#include <cstring>
#include <cmath>

/*Подниз на даден символен низ s наричаме всяка непрекъсната последователност от символи в s, включително празния низ и самия s.
Да се дефинира функция unsigned longestSequence (char* s), която намира дължината на най-дългия подниз на s, който се състои от еднакви букви.
Пример: за низа "abbbcc", това е числото 3, а за низа "abc" — числото 1.  */


unsigned recursion(char* s, int count, int current)
{
    if(s[current] != s[current+1]) return count+1;

    //std::cout<<s[current+1]<<"  ";
    return recursion(s, count+1, current+1);
}
unsigned longestSequence(char* s)
{
    /*unsigned allChars= 0;
    if(!s) allChars = 1;
    else return 0; */
    unsigned allChars = 1;

    int* position = new int[strlen(s)];
    position[0] = 0; 
    int t = 0;

    for(int i = 0; i<strlen(s); i++)
    {
        if(s[i] != s[i+1] && s[i+1] != '\0') 
        {
            allChars++;
            //std::cout<<i;
            t++;
            position[t] = i+1;

        }
    }

    int count = 0;
    unsigned max = recursion(s,count,position[0]);
    std::cout<<recursion(s,count,position[0])<<"  ";

    //std::cout<<allChars;
    for(int j = 1; j<allChars  ; j++)
    {
        std::cout<<j<<":"<<recursion(s,count,position[j])<<"  ";
         if(max <= recursion(s,count,position[j])) max = recursion(s,count,position[j]);

    }

    return max;
}

int main()
{
    char* str = new char[8];
    std::cin.getline(str, 8);
    std::cout<<longestSequence(str);

    return 0;
}