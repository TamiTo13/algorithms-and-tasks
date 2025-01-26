#include <iostream>


int main()
{
    int number;
    int berries = 0, peach = 0, briar = 0;
    short digit;
    do
    {
     std::cin>>number;
    }
    while(number%8 != 0 || number <= 0); 
    int N = 0;
    for (int p = 0; p<number/8; p++) //всеки бар код се състои от 8 числа
    {
        for(int i = 0; i<8; i++)
        {
           do
           {
            std::cin>>digit;
           }
           while (digit < 0 || digit > 9);
           
           if (i>2 && i<7)  N= N * 10 + digit; //работим само с четирицифрената цифра
        }
        if (N%7==0) berries++;
        else if (N%13==0) peach++;
        else if (N%17==0)  briar++;
        N = 0;   //зануляваме четирицифреното число, което разглеждаме, за му присвоим нова стойност
    }
    std::cout<< "Berry Jam: "<<berries<< std::endl;
    std::cout<<"Peach Jam: "<< peach<< std::endl;
    std::cout<< "Briar Jam: "<<briar<< std::endl;
}
  
