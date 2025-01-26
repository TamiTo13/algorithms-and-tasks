#include <iostream>

void task1()
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

void makeFalse(bool **check,int row,int column) //чисти матрицата от единиците (занулява)
{
    for(int i = 0; i<row; i++)
    for(int p = 0; p<column; p++)
    {
        check[i][p] = false;
    }
}
int outcome(const int row, const int column, char** table, int curRow, int curColumn, int moves, bool** check) //рекурсия,
{                                                                                                              //изчисляваща броя ходове за една 

    bool inside = (curRow>=0 && curRow < row) && (curColumn>=0 && curColumn < column); //дали е вътре в правоъгълника

  if (check[curRow][curColumn] == true || inside == false )
  {
      makeFalse(check, row, column); //занулява матрицата преди да я върне окончателна стойност
      return moves;
  }
  if( table[curRow][curColumn] == 'R')
  {
        check[curRow][curColumn] = true ;
         curColumn++; moves++;   //-> (колоните + 1)
  }
  else if(table[curRow][curColumn] == 'L')
  {
        check[curRow][curColumn] = true ; 
        curColumn--; moves++;    // <- (колоните -1)
  }
  else if( table[curRow][curColumn] == 'U')
  {
        check[curRow][curColumn] = true;
        curRow--; moves++; // (един ред нагоре (- 1))
  }
  else if( table[curRow][curColumn] == 'D')
  {
        check[curRow][curColumn] = true;
        curRow++; moves++;  // ред надолу (+1)
  }
  return outcome(row, column, table , curRow, curColumn, moves, check); //рекурсия
}

void maxFind(const int row, const int column, char** table, bool** check) //търсим най-големия outcome
{
    int moves = 0, rowPosition = 0, columnPosition = 0;
    int MAX = 0, current;
    for (int i = 0; i<row; i++)
    {
        for (int j = 0; j< column; j++)
        {
            current = outcome(row, column, table, i, j, moves, check);
            //std::cout<<outcome(row, column, table, i, j, moves, check);
            if (MAX < current)
            {
                 MAX = current; 
                 rowPosition = i; columnPosition = j; //координатите на най-големия outcome
            }

        }
    }
    std::cout<<std::endl<<"The row is"<<rowPosition<<" and the column is"<<columnPosition;
    delete []table;
    delete []check; //трием динамичните масиви
}

void task2_main() // Повикайте тази функция за проверка :)
{
    int row, column;
    std::cout<<"Rows: "; std::cin>>row;
    std::cout<<std::endl;
    std::cout<<"Rows: "; std::cin>>row;
    std::cout<<std::endl;

    char** table= new char*[row];
    bool** check = new bool* [row];

    for (int i= 0; i<row; i++)
    {
       table[i] = new (std::nothrow) char[column];
       check[i] = new (std::nothrow) bool[column];

       for(int j = 0; j<column; j++)
       {
           check[i][j] = false; //където е бил роботът, става true
           do
           {
            std::cin>>table[i][j];
           } while(table [i][j] != 'R' && table [i][j] != 'L' && table [i][j] != 'U' && table [i][j] != 'D');
        } 
    }

    maxFind(row, column, table, check);
}


int main()
{
    //task1();         //---> задача 1
    //task2_main();    // --> задача 2-1
}