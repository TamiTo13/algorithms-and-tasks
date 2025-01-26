
#include <iostream>
#include <ctime>



int pow_ten(int degree) //десет на степен degree (имах проблем с pow от cmath)
{
    int ten = 10;
    if(degree==0) return 1;
    for (int i = 1; i<degree; i++)
    {
        ten *= 10;
    }
    return ten;
}
bool checkzero(int number)  //Проверя дали числото няма нули
{
  int digit = number%10;
  while(number != 0)
  {
      if (digit ==0) return false;
      number /= 10;
      digit = number%10;
  }
  return true;
}

bool result(int random, int guess)
{
    int guess_digit,random_digit,bulls = 0,cows = 0;
    bool repeat_cows;   //Ако random е 1234,a guess-ът e 2522, да не ни извежда 3 крави
    int guess_copy = guess, random_copy = random;  
     for (int t = 0; t<4; t++)
     {
       random_digit = (random / pow_ten(t)) % 10;
       guess_digit = (guess / pow_ten(t)) % 10;
      
       //std::cout<<guess<<"   "<<guess_digit<<"   "<<random<<"   "<<random_digit<<std::endl;  //проверка
       if (random_digit == guess_digit)
       {
           bulls++;
           random = random - random_digit * pow_ten(t); //зануляваме местата,където срещаме бикове, за да не ги причислим към кравите
            if(bulls==4)                                      
            { 
                std::cout<<"you guessed it right!"<<std::endl; //При четири бика - game over
                return true;
            }                                                     
       }                                                        
     }


     for (int i = 0; i<4; i++)
    {
        random_digit = (random / pow_ten(i)) % 10;
        repeat_cows = false;     // ако стане true, не пречислява една и съща цифра към кравите по няколко пъти
        guess_copy= guess;  
        for(int p= 0; p<4; p++)
        {
            guess_digit = guess / ( pow_ten(p)) % 10 ;  
            if (guess_digit == random_digit && guess_digit!=0 && repeat_cows == false)  //на местата, където сме намерили бикове, има нули
            {
                cows++;
                //std::cout<<guess<<"   "<<guess_digit<<"   "<<random<<"   "<<random_digit<<std::endl; //проверка
                guess = guess - guess_digit * pow_ten(p); // не искаме една цифра да се причисли по няколко пъти като крава
                repeat_cows = true;     
            }
        }      
    }
    std::cout<<"You have "<<bulls<<" bulls and "<<cows<<" cows."<<std::endl;
    return false; //Играта все още не е приклчила
}
int main()
{ 
    std::cout<<"How many attempts do you wish to have?"<<std::endl;
    int counterN;  std::cin>>counterN;
    int random,guess;
    srand(time(0));
   do
    {
    random = rand() % 8889 + 1111; //най-малкото четирицифрено число без нули е 1111
    //std::cout<<random<<std::endl;  // проверка
    }
    while(!checkzero(random));  //цикълът не спира докато не се намери число без нула

bool game_over = false;
while( counterN > 0 && game_over == false) 
{
    do
    {
         std::cout<<"Take a guess"<<std::endl;
         std::cin>>guess; 
    } while (guess<1000 || guess>9999);
    game_over = result(random,guess);
    counterN--;
}
  if (game_over != true) std::cout<<"you lost, the number was "<<random<<std::endl;
   
    return 0;
}