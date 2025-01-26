#include <iostream>
#include <cmath>

const double radius = 4;
const double epsilon = 1e-3; //работим с точност до третата нула

bool circle (double x, double y)
{
    double coordinate = sqrt((x*x) + (y*y));
    if (coordinate <= (radius+epsilon)) return true;
    return false;  /*----> if(coordinate > radius) */
}

bool black(double x, double y)
{
    bool check = (y>=(-7-epsilon) || y <= (-6-epsilon)) && (x>=(-2-epsilon) || x<= (2+epsilon));
    return check;
}

void first_quadrant (double tg, double x)
{
    double tgx = fabs(tg-1);  
        if (tgx<=epsilon)      // за tg== 1.000123313 (примерно), ще го причисли за tg == 1.000;
     {
        std:: cout<<"On the line between green and yellow";
     }
      else if(tg<1)
      {
          double check = fabs(x-2.8); //ако имаме x==2.80077777, причисляваме го като x==2.800
         if (check<=epsilon)std::cout<<"On the line between yellow and purple"; //случаят, в който x==2.8
         else { x<2.8? std::cout<<"yellow" : std::cout<< "purple"; };
 
     }
       else if (tg>1)
     {
          std:: cout<<"green";
     }
}

void second_quadrant (double tg,double x)
{
    double tgx = fabs(tg+1);  //сменяме на +1, защото tg 135(90+45) градуса е -1
      if (tgx<epsilon)
     {
        std:: cout<<"On the line between red and pink";
     }
     else if(tg>-1)
     {
        double check = fabs(x+2.8); //тук x-ът е <0, затова е +2.8
         if (check<epsilon)std::cout<<"On the line between pink and white";
         else { x<2.8? std::cout<<"pink" : std::cout<< "white"; };

     }
       else if (tg<-1)
     {
        std:: cout<<"red";
     }
}
 void third_quadrant(double tg, double x)
 {
     double tgx = fabs(tg-1);
    if (tgx<epsilon)
     {
        std:: cout<<"On the line between blue and pink";
     }
     else if(tg<1)
     {
         double check = fabs(x+2.8);
         if (check<epsilon)std::cout<<"On the line between pink and white";
         else { x<2.8? std::cout<<"pink" : std::cout<< "white?"; };

     }
      else if (tg>1)
     {
        std:: cout<<"blue";
     }
 }
  void forth_quadrant(double x)  //тук не използваме tg(-45)=-1,защото не ни трябва(само x-ът е от значение в този квадрант)
  { 
         double check = fabs(x-2.8);
         if (check<epsilon)std::cout<<"On the line between yellow and purple";
         else { x<2.8? std::cout<<"yellow" : std::cout<< "purple"; };
  }
  void Oxy(double x, double y)
  {
      if (fabs(x)<epsilon) //x==0 (дори за x == 0.00012312314)
      {
          y>0? std::cout<<"On the line between green and red":std::cout<<"On the line between blue and yellow";
      }
      else if(fabs(y)<epsilon) //y==0 (дори за y = 0.00013123134)
      {
          if (x > 0)
          {
            if(fabs(x-2.8) < epsilon) std::cout<<"On the line between yellow and purple";

            else x>2.8? std::cout<<"purple" : std::cout<< "yellow";
          }
          else //(x<0)
          {
            if(fabs(x+2.8) < epsilon) std::cout<<"On the line between pink and white";

            x>2.8? std::cout<<"white": std::cout<<"pink"; 
          }
      }
  }

  void find(double x, double y)
{
    double tg = y/x; //tg(45) = 1, tg(135) = -1, в зависимост от това колко е ъгъла,правата (x,y) ще лежи под нея или над нея
    if(x>0 && y>0) first_quadrant(tg,x);
    else if(x<0 && y>0) second_quadrant(tg,x); 
    else if(x<0 && y<0) third_quadrant(tg,x);
    else if(x>0 && y<0) forth_quadrant(x);
    else Oxy(x,y);
} 

int main()
{   
  double x, y;
  std::cout<<"How much is x?"<<std::endl;
  std:: cin>>x;
  std::cout<<"How much is y?"<<std::endl;
  std:: cin>>y;
  if (fabs(x)<epsilon && fabs(y)<epsilon) std::cout<<"Center";  //ако е в центъра
  else if (circle(x,y))find (x,y);     //Ако е в кръга, извежда в кой цвят е (включен е и белия)
  else if (black(x,y)) std:: cout<<"black rectangle";  //ако не е в кръга, гледа дали е в черния правоъгълник
  else std::cout<<"Outside of circle" ;    //ако не е нито едно от трите
  
}