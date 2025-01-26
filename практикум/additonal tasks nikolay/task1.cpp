#include <iostream>
#include <cstring>

/*
Дадена е квадратна матрица с размери nxn, n която описва лабиринт. 
Стойност 0 в дадена клетка означава „стена“, стойност 1 означа „свободно място за движение“. 
Даден е низ съдържащ само буквите E(east), W(west), N(north) и S(south), които указват едностъпкови придвижвания в съответните географски посоки.
Да се напише функция, която проверява дали даденият низ е валиден път от някоя проходима клетка в лабиринта до долния десен ъгъл в лабиринта.
 */
bool check(char* str, int x, int y, int finishX, int finishY, char** matrix)
{
    while(*str)
    {

        if(*str != 'N' && *str != 'S' && *str != 'W' && *str != 'E')
        {
            std::cerr<<"Invalid output";
            return false;
        }

        switch(*str)
        {
        case 'N':
        x = x-1;
        break;
        case 'S':
        x = x+1;
        break;
        case 'W':
        y = y-1;
        break;
        case 'E':
        y = y+1;
        break;
        }

        if(matrix[x][y] == '0') return false;
        ++str;
    }
    if(x == finishX && y == finishY) return true;
    return false;

}

void input(char** arr, int size)
{
    for(int i = 0; i<size;i++)
    {
        for(int j =0; j<size;j++)
        {
            std::cin>>arr[i][j];
        }
    }
}

int main()
{
    int n;
    std::cin>>n;
    char** arr = new char*[n];

    for(int i = 0; i<n;i++)
    {
        arr[i] = new char[n];
    }

    input(arr, n);
    
    char* path = new char[32];
    strcpy(path,"ESESESW" );
    std::cout<<check(path, 0,0,3,2, arr);
}