#include <iostream>
#include <cmath>

int main()
{
    const double kML=400;
    int k,l,ml;
    double kolichestvo_butilki;
    errorcase: std::cout<<"Въведи броя на учениците, и литрите,милилитрите на бутилката.";
    std::cin>>k>>l>>ml;
    int butilka=l*1000 + ml;
    if ((ml<0 || ml>=1000) || (l<0 || l>20))
    {
        std::cout<<"Error!";
        goto errorcase;
    }
    else
    {
       int kolichestvo=k*kML;
       kolichestvo_butilki=kolichestvo/butilka;
       ceil(kolichestvo_butilki);
       std::cout<<kolichestvo_butilki;
    }
    return 0;
}