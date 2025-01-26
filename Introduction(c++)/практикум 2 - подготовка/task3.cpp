#include <iostream>
#include <cmath>

const float EPS = 0.00001;


bool check(const int a, const int b, const int c, int result) 
{
    double x1 = (double)(-b + sqrt( b*b - 4*a*c ) ) / 2*a;
    std::cout<<"x1: "<<x1<<std::endl;

    double x2 = (double)(-b - sqrt( b*b - 4*a*c ) ) / 2*a;
    std::cout<<"x2: "<<x2<<std::endl;

    std::cout<<std::endl;
    //if (x1 - round(x1) > EPS && x2 - round(x2) > EPS) return false; 

    if(x1 - result < EPS || x2 - result < EPS) return true;
    else return false;
}

void formula(int a, int b, int c,int result) 
{
    std::cout<<a<<"x*x + "<<b<<"x + "<<c<<" = "<<result;
}

void printOut(int* arr, int* results, int N, int K)
{
    for(int i = 0; i<3*N;i += 3)
    {
        for(int j = 0;j<K;j++)
        {
            if(check(arr[i], arr[i+1], arr[i+2], results[j])) 
                formula(arr[i], arr[i+1], arr[i+2], results[j]);
        }
    }
}

int main()
{
    int N;
    std::cin>>N;

    int* arr = new (std::nothrow) int[3*N];
    if(!arr)
    {
        std::cerr<<"Nemash mesto";
        return 1;
    }

    for(int i = 0; i<N;i++)
    {
        for(int j = 0; j<3; j++)
        {
            std::cin>>arr[i+j];
        }
    }

    int K;
    std::cin>>K;

    int* results=new (std::nothrow) int[K];
    if(!results)
    {
        delete[] arr;
        arr = nullptr;
        std::cerr<<"Memory";
        return 1;
    }

    for(int i=0; i<K;i++)
    {
        std::cin>>results[i];
    }

    printOut(arr, results, N, K);

    delete[] arr;
    delete[] results;

    return 0;
}