#include <iostream>
#include <cmath>

const double radius = 4.;

bool circle (double x, double y)
{
    double coordinate = sqrt((x*x) + (y*y));
    if (coordinate <= radius) return true;
    return false;  /*----> if(coordinate > radius) */
}
short quadrant (double x, double y)
{
    if(x>0 && y>0) return 1;
    if(x<0 && y>0) return 2; 
    if(x<0 && y<0) return 3;
    if(x>0 && y<0) return 4;
}

short find(double x, double y)
{
   double tg = y/x;
   short scope = quadrant(x,y);
   if (scope == 1)
   {
     first_quadrant(tg,x);
   }
   else if (scope == 2)
   {
    second_quadrant(tg,x);
   }
   else if (scope == 3)
   {
       third_quadrant(tg,x);
   }
   else if (scope == 4)
   {
       forth_quadrant(tg,x);
   }
} 

void first_quadrant (double tg, double x)
{
        if (tg>1)
     {
         std:: cout<<"green";

     }
     else if(tg<1)
     {
         x<2.8? std::cout<<"yellow" : std::cout<< "purple";
 
     }
}

void second_quadrant (double tg,double x)
{
      if (tg<-1)
     {
        std:: cout<<"red";

     }
     else if(tg>-1)
     {
         x<2.8? std::cout<<"pink" : std::cout<< "white?";

     }
}
 void third_quadrant(double tg, double x)
 {
         if (tg>1)
     {
         std:: cout<<"blue";

     }
     else if(tg<1)
     {
         x<2.8? std::cout<<"pink" : std::cout<< "white?";

     }
 }
  void forth_quadrant(double tg, double x)  
  { 
      if (tg>-1)
     {

         x<2.8? std::cout<<"yellow" : std::cout<< "purple";
     }
     else if(tg<-1)
     {
         std::cout<<"yellow";
     }
  }

int main()
{   
  double x, y;
  std:: cin>>x>>y;
  if (circle(x,y))find (x,y);
  else std::cout<<"Outside of circle" ;
  
}