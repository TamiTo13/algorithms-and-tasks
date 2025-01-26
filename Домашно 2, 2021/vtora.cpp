#include <iostream>

int main()
{
    int rows1, rows2, columns1, columns2;
    std::cout << "N1: "<< std::endl; std::cin>>rows1 ;
    std::cout << "M1: "<< std::endl; std::cin>>columns1 ;
    std::cout << "N2: "<< std::endl; std::cin>>rows2 ;
    std::cout << "M2: "<< std::endl; std::cin>>columns2 ;
    int** p = new int*[rows1];
    int** dc = new int*[rows2];

    for (int i = 0; i < rows1; i++)
    {
        p[i] = new int[columns1];
    }

    for (int i = 0; i < rows2; i++)
    {
        dc[i] = new int[columns2];
    }

    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < columns1; j++)
        {
            std::cin>>p[i][j];
        }

    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < columns2; j++)
        {
            std::cin>>dc[i][j];
        }

    //for (int i = 0; i < 4; i++)
   // {
     //   for (int j = 0; j < 4; j++)
      //  {
      //      std::cout << p[i][j];
       // }
       // std::cout << std::endl;
    //}


    //std::cout << std::endl;


    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            if (j==columns2-1 && columns1 > columns2)
            {
                int *buffer = new int[columns2];
                for (int t = 0; t < columns2; t++)
                {
                    buffer[t] = p[i][t];
                }

                delete p[i];

                p[i] = new int[columns2];
                for (int l = 0; l < columns2; l++)
                {
                    p[i][l] = buffer[l];
                }

                delete []buffer;
            }
            if (i > rows2-1) delete p[i];
        }
    }

     for (int i = 0; i<rows1;i++)
     for (int j = 0; j <columns1; j++)
     {
         if (p[i][j] < dc [i][j]) p[i][j] = dc[i][j];
         else if (p[i][j] > dc [i][j]) p[i][j] *= -1;
     }

    std::cout << std::endl;

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            std::cout << p[i][j];
        }
        std::cout << std::endl;
    }

}