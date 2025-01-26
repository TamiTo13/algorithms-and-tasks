#include <iostream>
#include <cmath>


int main()
{
    errorcase: std::cout<<"Въведи числата";
    std::cin>>chislo1>>chislo2;
    switch(chislo1)
    {
        case 1: break;
        case 6: chislo1=9; break;
        case 8: break;
        case 9: chislo1=6; break;
        default:
        cout<<"Въведи 1,6,8 или 9"; goto errorcase;
    }
    switch(chislo2)
    {
        case 1: break;
        case 6: chislo2=9; break;
        case 8: break;
        case 9: chislo2=6; break;
        default:
        cout<<"Въведи 1,6,8 или 9"; goto errorcase;
    }
    std::cout<<max(chislo1,chislo2)<<" "<<min(chislo1,chislo2);
    return 0;
}