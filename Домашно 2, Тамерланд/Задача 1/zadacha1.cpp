#include <iostream> 
#include <cmath>
using namespace std;

const int maxVisochina = 20;
const int maxShirochina = 40;
const int minParametur = 4;

int position(int poziciq, int visochina, char pole[][maxShirochina]){  //Намира най-ниската възможна височина, на която може да се постави
 int i= visochina-1;                                                   //Ако колоната е пълна, връща -1
  for (; i>=0; --i)
  {
    if (pole[i][poziciq-1] =='\0') 
    {
      return i;
    }
  }
  return -1;
}

void print(int visochina, int shirochina,char pole[][maxShirochina])   //Извежда полето за игра
{
   for (int i = 0; i<visochina; i++)
   {
      for ( int p=0; p<shirochina; p++)
      {
        cout<<"|";
        if(pole[i][p] != '\0')cout<<pole[i][p]; //Елементите на pole[]могат да бъдат само:  '\0', 'o' , 'x'
        else { cout<<" "; }
      }
      cout<<endl;
   }
}

bool checkWin(int visochina,int shirochina, char pole[][maxShirochina]) //Проверя дали има наредени 4
{
  for (int i=0; i<visochina; i++)
  {
    for(int p=0; p<shirochina; p++)
    {
      bool caseStraightOy = (pole[i][p]==pole[i][p]) && (pole[i+2][p] == pole[i][p]) &&           // Ако са наредени вертикално
                              (pole[i+3][p] == pole[i][p])  && (pole[i][p]!='\0')           ;
      
      bool caseStraightOx = (pole[i][p+1] == pole[i][p]) && (pole[i][p+2] == pole[i][p]) &&      //Ако са наредени хоризантално
                              (pole[i][p+3] == pole[i][p]) && (pole[i][p]!='\0')            ;

      bool caseXEqualsY = (pole[i+1][p-1] == pole[i][p]) && (pole[i+2][p-2] == pole[i][p]) &&    //Диагонално
                              (pole[i+3][p-3] == pole[i][p]) && (pole[i][p]!='\0') ;

      bool caseXEqualsMinusY = (pole[i-1][p-1] == pole[i][p]) && (pole[i-2][p-2] == pole[i][p]) && //Диагонално  
                              (pole[i-3][p-3] == pole[i][p]) && (pole[i][p]!='\0');  
     
     bool check = caseStraightOy || caseXEqualsY || caseXEqualsMinusY || caseStraightOx ;
     
     if(check) return true;
     
  }
}
return false;
}


int main (){
  int visochina,shirochina, poziciq; 
  int probnaVisochina; int counter=0;
  bool player = true; bool check = false;
  ErrorCase: cout<<"Declare height(between 4 and 20) and width(between 4 and 40) of the table."<<endl;
  cin>>visochina>>shirochina;
  if(visochina < minParametur || shirochina < minParametur || visochina > maxVisochina || shirochina> maxShirochina)
  {
    cout<<"Please correct."<<endl; goto ErrorCase;
  }
  char pole[visochina][maxShirochina] = {'\0'};
  cout<<position(1, visochina,pole)<<endl;
  print(visochina,shirochina+1,pole);
  do
  {
  fullColumn: player? cout<<"Player 1 turn:" :  cout<<"Player 2 turn: ";
  cin>>poziciq;
  if(poziciq >shirochina || poziciq < 1)
  {
    cout<<"Please enter correct coordinates(bigger than 1 and smaller than "<<shirochina<<")";
  }
  probnaVisochina = position(poziciq, visochina, pole);
  if(probnaVisochina == -1)
  {
    cout<<"Column is full."<<endl<<endl;
    goto fullColumn;
  }
  cout<<endl;
  if(player) {pole[probnaVisochina][poziciq-1]='o';}   //Player 1(x) => bool player =true
  else {pole[probnaVisochina][poziciq-1]='x';}         //Player 2(o) => bool player = false
  print(visochina,shirochina+1,pole);
  player? player=false:player=true;       //Редуване на играчите
  check=checkWin(visochina,shirochina,pole); //При победа се извежда true и цикъла се прекъсва
  } while(!check);
  cout<<endl<<endl<<endl;
  player? cout<<"Player 2 wins!" : cout<<"Player 1 wins!" ;
  return 0; 
}