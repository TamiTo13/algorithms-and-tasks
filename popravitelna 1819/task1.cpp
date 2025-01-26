#include <iostream>
#include <cstring>
using namespace std;

/* Дадени са символни низове, съставени от малки латински букви и интервали (Σ = { 'a', 'b', …, 'z', ' ' }). “Кодиране” на низ s наричаме функция codes : Σ ➝ Σ, която замества всяка буква от s с произволна буква от Σ, а буквите от Σ, които не се срещат в s, оставя непроменени. Да се дефинира функция 

void encode ([подходящ тип] s1, [подходящ тип] r1, [подходящ тип] s2, [подходящ тип] r2), 

където s1, r1, s2 и r2 са символни низове. Функцията да намира кодирането, което преобразува s1 в r1 и, ако такова съществува, да преобразува със същото кодиране низа s2, като резултата да запише в r2. Ако такова кодиране не съществува, в r2 да се запише празен низ.

Примери:

encode("hello","worrd","love",result) ще запише в result низа "rdvo"
encode("hello","world","love",result) ще запише в result празния низ */

void fillArr(char* one, char* two, char*& model) //запълваме масив model (моделът, по който encode-ваме)
{
    if(strlen(one) != strlen(two)) //трябва да са с равна дъжина, за да съответстват
    {
        model = nullptr;
        return;
    }
    for(int i = 0; i<strlen(one); i++)
    {
        model[i] =one[i];               
        model[i+strlen(one)] = two[i];   //до средата на model запълваме със s1, другата половина с r1
    }
}

bool checkArr(char* model) //проверка дали има съответствие между буквите на s1 и r1 (worrd = abccd -da, worrd = abcde - ne)
{
    for(int i = 0; i<strlen(model)/2;i++)
    {
        for(int j = i+1; j< strlen(model) / 2 ;j++)
        {
            if(model[i] == model[j])
            {
                if(model[i + strlen(model) / 2] != model[j + strlen(model) / 2]) return false;
            }
        }
    }
    return true;  
}

void encode(char* s1,char* r1, char* s2, char*& r2)
{
    char* model = new char[2*strlen(s1)];
    fillArr(s1,r1,model);
    if(!checkArr || model ==nullptr)
    {
        std::cout<<"such encoding does not exist";
        r2 = nullptr;
        return;
    }
    
    //bool replaced;
    for(int i = 0; i<strlen(s2); i++)
    {

        for(int j = 0; j<strlen(model) / 2; j++)
        {
            if(s2[i] == model[j] )
            {
                r2[i] = model[j + strlen(model) / 2];
                //replaced = true; //break alternative
            }
        }
    }




}

int main()
{
    char* s1 = new char[256];
    std::cin.getline(s1, 256);

    char* r1 = new char[256];
    std::cin.getline(r1, 256);

    char* s2 = new char[256];
    std::cin.getline(s2, 256);

    char* r2 = new char[strlen(s2) + 1];
    strcpy(r2,s2);

    encode(s1, r1,s2,r2);
    std::cout<<r2;
}