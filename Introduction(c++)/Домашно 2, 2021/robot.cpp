#include <iostream>

void makeFalse(bool **check,int row,int column)
{
    for(int i = 0; i<row; i++)
    for(int p = 0; p<column; p++)
    {
        check[i][p] = false;
    }
}
int outcome(const int row, const int column, char** table, int curRow, int curColumn, int moves, bool** check)
{

    bool inside = (curRow>=0 && curRow < row) && (curColumn>=0 && curColumn < column);

  if (check[curRow][curColumn] == true || inside == false )
  {
      makeFalse(check, row, column);
      return moves;
  }
  if( table[curRow][curColumn] == 'R')
  {
        check[curRow][curColumn] = true ;
         curColumn++; moves++; 
  }
  else if(table[curRow][curColumn] == 'L')
  {
        check[curRow][curColumn] = true ; 
        curColumn--; moves++;
  }
  else if( table[curRow][curColumn] == 'U')
  {
        check[curRow][curColumn] = true;
        curRow--; moves++; 
  }
  else if( table[curRow][curColumn] == 'D')
  {
        check[curRow][curColumn] = true;
        curRow++; moves++; 
  }
  return outcome(row, column, table , curRow, curColumn, moves, check);
}

void maxFind(const int row, const int column, char** table, bool** check)
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
                 rowPosition = i; columnPosition = j;
            }

        }
    }
    std::cout<<std::endl<<"The row is"<<rowPosition<<" and the column is"<<columnPosition;
}

int main()
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
           check[i][j] = false;
           do
           {
            std::cin>>table[i][j];
           } while(table [i][j] != 'R' && table [i][j] != 'L' && table [i][j] != 'U' && table [i][j] != 'D');
        } 
    }

    maxFind(row, column, table, check);
    delete []table;
    delete []check;
}