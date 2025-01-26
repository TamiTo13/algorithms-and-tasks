#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

 const unsigned short maxLimit = 8194;

 bool equal(char arrayOne[], char arrayTwo[]) //Проверява дали вата масива съпадат.(дали числата са равни)
 {
   for(int i=0; i<maxLimit; i++)
   { 
       if(arrayOne[i]=='\0' || arrayTwo[i]=='\0') continue;
       if (arrayOne[i]!=arrayTwo[i])
       {
           return false;
       }
   }
   return true;
 }

 bool comparison(char arrayOne[], char arrayTwo[]) //В случай, че не са равни, ги сравнява
 {
     int size_of_arrayOne=0; int size_of_arrayTwo = 0;
     for (int t=0; t<maxLimit; t++)
     {
        if (arrayOne[t] != '\0') size_of_arrayOne++;
        if (arrayTwo[t] != '\0') size_of_arrayTwo++;
     }
     if (size_of_arrayOne>size_of_arrayTwo) return true;
     if (size_of_arrayTwo>size_of_arrayOne) return false;

     for(int i=0; i<maxLimit; i++)
     { 
         if (arrayOne[i]>arrayTwo[i]) return true;
         else if (arrayTwo[i]>arrayOne[i]) return false;
     }
 }

 bool printArray(char array[]) //Извежда масива
{
  for(int i = 0; i<maxLimit; i++)
        {
            if(array[i]<'0' || array[i]>'9') continue;
            cout<<array[i];
        }
}

void clear_starting_zeroes(char array[]) // "Чисти" предностоящите нули. (001234=>1234)
{
  int size_of_array=0;
  for(int i=0; i<maxLimit;i++)
  {    if(array[i] != '0') size_of_array++;
       if(array[i]=='0' && size_of_array == 0)
       {
           for (int p = i; p<maxLimit-1; p++)
           {
               array[p]=array[p+1];
           }
           i-=1;
       }
          array[maxLimit - 1] = {'\0'};
  }
  }

void clearArray(char array[],char new_array[]) // "Чисти" всичк елементи освен числата (1ab2  3__ ==> 123), като ги прехвърля на друг масив
{   clear_starting_zeroes(array);
    clear_starting_zeroes(new_array);
    for (int t= 0; t<maxLimit; t++)
    {
       if(array[t]<'0' || array[t]>'9')
       {
           for (int p = t; p<maxLimit-1; p++)
           {
               array[p]=array[p+1];
           }
          array[maxLimit - 1] = {};
       }
    }
    int n1 = 0; // елементите на новия масив, с който ще работим
    for (int n = 0; n<maxLimit; n++)
    {
        if (array[n]>='0' && array[n]<='9')
        {
            new_array[n1]=array[n];
            n1++;
        }
    }
}

void Sum(char arrayOne[], char arrayTwo[], char result[]) //Изчислява сумата от двете числа
{
  char arrayOneSum[maxLimit] ={} ; char arrayTwoSum[maxLimit] = {};
    int arrayoneSum,arraytwoSum; int p1= 0; int p2 = 0; int SUM;
    int ostatuk = 0;
   for (int i = maxLimit-1; i>=0; i--)
   {
       if (arrayOne[i]!='\0')
       {
        arrayOneSum[p1]=arrayOne[i]; p1+=1;
       }
       if (arrayTwo[i]!='\0')
       {
        arrayTwoSum[p2]=arrayTwo[i]; p2+=1;
       }
   }
   int p = 0; // за result[]
   for(int t=0; t<maxLimit; t++)
   {
       if((arrayOneSum[t]>='0' && arrayOneSum[t]<='9') || (arrayTwoSum[t]>='0' && arrayTwoSum[t]<='9') )
       {
             arrayOneSum[t] !='\0'? arrayoneSum = arrayOneSum[t] : arrayoneSum =0;
             arrayTwoSum[t] !='\0'? arraytwoSum = arrayTwoSum[t] : arraytwoSum =0;
             SUM =(arrayoneSum + arraytwoSum + ostatuk) % 10;
             result[p]=SUM; p+=1; 
             ostatuk = (arrayoneSum + arraytwoSum + ostatuk)/ 10;
       }
   }
}

int main(){

    char firstArrayDemo[maxLimit]= {}; char firstArray[maxLimit] = {};
    char secondArrayDemo[maxLimit]= {}; char secondArray[maxLimit] = {};
    cout<<"Enter the first number:"<<endl;
    cin.getline(firstArrayDemo, maxLimit);
    clearArray(firstArrayDemo, firstArray);
    cout<<endl;
    cout<<"Enter the second number:"<<endl;
    cin.getline(secondArrayDemo, maxLimit);
    clearArray(secondArrayDemo, secondArray);
    cout<<endl;

        printArray(firstArray);
        equal(firstArray, secondArray) ? cout<<" == " : cout<<" != ";
        printArray(secondArray);  cout<<endl; 
        
                                                        //Checks is the two numbers are equal
    if(!equal(firstArray, secondArray))                                            
    { 
      printArray(firstArray);                                                                       //IF they are not the same
      comparison(firstArray,secondArray) ? cout<<" > " : cout<<" < " ;
      printArray(secondArray); cout<<endl;
    }

    char sumDemo[maxLimit+1]; char sum[maxLimit+1] = {};
    Sum(firstArray, secondArray, sum);
    printArray(firstArray); cout<<" + ";
    printArray(secondArray); cout<<" = ";
    printArray(sum);
    return 0;
}