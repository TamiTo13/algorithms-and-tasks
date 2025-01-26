#include <iostream>
#include <cmath>
#include <windows.h>
using std::cout;
using std::endl;
using std::cin;


void print (char leftEnd, char rightEnd, char ready, char not_ready,int length, double seconds_per_bar, bool percents)
{
  double progress = 0.0;
  double progress_step= (1./length)*100;   //с колко процента ще се увеличи след една стъпка
  char bar[length]; bar[0]=leftEnd; bar[length-1]=rightEnd;
  for(int i = 1;i<length-1;i++)
  { if (i==(length-1)/2 && percents)
    {
     bar[i+2]='%'; i=i+3;; //Оставяме две "свободни"(празни) места по средата за процентите и запълваме следващата позиция с %
    }
    bar[i]=not_ready;
  }             //Създаваме масива, готов за ползване (бара е на 0%)
  
  
  for(int t=0; t<length;t++)
  {  
     if (t!=0 && t!=length-1 && bar[t]!='%') bar[t]=ready;   // 
     progress+=progress_step;
     if(progress>=100 && percents)
     {
       progress=100;
       bar[1]='\0';          //Когато процентите станат 100, редът се увеличава с един символ => (ред 40)
     } 
     for (int p=0;p<length;p++)
     {
       if(p==(length-1)/2 && percents)
       {
        cout<<ceil(progress);
        p+=1;                                                            
        continue;
       }
      if(bar[p]!='\0')cout<< bar[p];
     }                                            //с всяка "крачка" на масива прогресът се увеличава с progress_step процента
     Sleep(seconds_per_bar*1000);
     if(t !=length-1)system("cls");
  }

}

int main(){
    int seconds,length; bool percents;
    char leftEnd='<'; char rightEnd='>'; char ready='='; char not_ready= '-';
    ErrorSec: cout<<"Enter seconds:";
    cin>>seconds;
    if (!cin || seconds < 1)
    {
      cout<<"please enter correct value of the seconds"<<endl; goto ErrorSec;
    }
    ErrorLen: cout<<"Enter the length of the bar:";
    cin>>length;
    if (!cin || length < 1)
    {
      cout<<"please enter correct value of the length"<<endl; goto ErrorLen;
    }
    ErrorPercents: cout<<"Do you want to see the percents?(Type 1 for yes and 0 for no)";
    cin>>percents;
    if (!cin || (percents!=0 && percents !=1))
    {
      cout<<"please enter correct value"<<endl; goto ErrorPercents;
    } 
    cout<<endl;
    double seconds_per_bar = (double)seconds/length;
    print(leftEnd,rightEnd,ready,not_ready,length,seconds_per_bar, percents);
    cout<<"   It is ready!";
    return 0;
}