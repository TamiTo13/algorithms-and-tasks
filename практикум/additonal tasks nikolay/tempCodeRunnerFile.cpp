#include <iostream>

int main()
{
      bool** table = new bool*[4];
    for(int i = 0; i<4;i++)
    {
        table[i] = new bool[4];
    }

    table= {0,};

    for(int i = 0; i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            std::cout<<table[i][j];
        }
    }


}