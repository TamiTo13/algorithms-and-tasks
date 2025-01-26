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

    std::cout << std::endl;

    for (int i = 0; i < rows1; i++) //задаваме, че всеки един от rows на брой показатели сочи към 
    {                               // columns на брой ,,квадратчета'' от паметта
        p[i] = new int[columns1];
    }

    for (int i = 0; i < rows2; i++) 
    {
        dc[i] = new int[columns2];
    }

    for (int i = 0; i < rows1; i++)          //въвеждаме масивите
        for (int j = 0; j < columns1; j++)
        {
            std::cin>>p[i][j];
        }

       

    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < columns2; j++)
        {
            std::cin>>dc[i][j];
        }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            if (j==columns2-1 && columns1 > columns2)  //в момента, в който пресечем прага на втората матрица влизаме в тялото
            {
                int *buffer = new int[columns2];       //въвеждаме си трети, едномерен масив, който ще ни служи като буфер
                for (int t = 0; t < columns2; t++)
                {
                    buffer[t] = p[i][t];   //в буфера пренасяме само columns2 на брой елемнта, а после изтриваме целия ред
                }

                delete p[i];

                p[i] = new int[columns2];
                for (int l = 0; l < columns2; l++)
                {
                    p[i][l] = buffer[l];     //пренасяме елементите на буфера в изтрития ред
                }

                delete []buffer;   //трием буфера
            }
            if (i > rows2-1 && rows1 > rows2 ) delete p[i];  //ако прекрачим прага, трием излишния ред
        }
    }

     for (int i = 0; i<rows1;i++)
     for (int j = 0; j <columns1; j++)   //преобразувания
     {
         if (p[i][j] < dc [i][j])    p[i][j] = dc[i][j];
                                    

         else if (p[i][j] > dc [i][j])   p[i][j] *= -1;
                                    
     }

    std::cout << std::endl <<"Matrix A:" << std::endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            std::cout << p[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}