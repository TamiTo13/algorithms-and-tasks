#include <iostream>
#include <cmath>


int main()
{
    double Ax, Ay, Bx, By, Cx, Cy;
    std::cout<<"Въведи x първата точка.";
    std::cin>>Ax;
    std::cout<<"Въведи y първата точка.";
    std::cin>>Ay;
    std::cout<<"Въведи x втората точка.";
    std::cin>>Bx;
    std::cout<<"Въведи y втората точка.";
    std::cin>>By;
    std::cout<<"Въведи x третата точка.";
    std::cin>>Cx;
    std::cout<<"Въведи y третата точка.";
    std::cin>>Cy;
    double a,b,c;
    a=sqrt(pow(Ax-Bx,2.)+pow(Ay-By,2.));
    b=sqrt(pow(Bx-Cx,2.)+pow(By-Cy,2.));
    c=sqrt(pow(Cx-Ax,2.)+pow(Cy-Ay,2.));
    double p = (a+b+c)/2;
    double S=sqrt (p*(p-a)*(p-b)*(p-c));
    if (S!=0)
    {
    std::cout<<"Точките не лежат на една права.";
    }
    else
    {
    std::cout<<"Точките лежат на една права.";
    }
    return 0;
}