#include <iostream>
#include <cstring>

/*bool wordLength(int counter)
{
    return counter>=9;
} */

bool isEqual(char* one, char* two, int counter)
{
    for(int i = 0; i<counter; i++)
    {
        if(one[i] != two[i]) return false;
    }
    return true;
}

int* FindCoordinates(char c[][3], char first)
{
    unsigned arrSize = 0;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if (first == c[i][j]);
                arrSize ++;
        }
    }

    int t = 1;
    int* coordinates = new int[arrSize+1];
    coordinates[0] = arrSize;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if (first == c[i][j])
            {
                coordinates[t++] = i;
                coordinates[t++] = j;
            }
                     
        }
    } 

    return coordinates;   
} 

bool outOfBounds(int x, int y)
{
    return x<0 || x>2 || y<0 || y>2;
}

bool recursion(char c[][3], char word[9], char newWord[9], unsigned counter, int x, int y)
{
    if(outOfBounds(x,y)) return false;

    if(isEqual(newWord, word, 9)) return true;
    else if(!isEqual(newWord, word, counter) && counter != 0) return false;

    newWord[counter++] = c[x][y];

    x = x + 1;
    if( !recursion(c, word, newWord, counter, x, y) )
    {
        counter--;
        x = x-1;
    }
    else return true;

    y = y+1;
    if(!recursion(c,word, newWord, counter,x, y))
    {
        counter--;
        y = y-1;
    }
    else return true;

    x = x-1;
    if(!recursion(c, word,newWord, counter,x,y))
    {
        counter--;
        x = x+1;
    }
    else return true;


    y = y-1;
    if(!recursion(c, word,newWord,counter, x, y))
    {
        counter--;
        y=y+1;
    }
    else return true;

    return false;

}

bool crossword (char c[][3], char words[][9], unsigned int n)
{
    int* coordinates;
    int currentCoordinate = 1;
    for(int i = 0; i<n;i++)
    {
        coordinates = FindCoordinates(c, words[n][0]);
        while (coordinates[0])
        {
        unsigned counter = 0;
        char newWord[9];
        if(recursion(c, words[i], newWord, counter, coordinates[currentCoordinate], coordinates[currentCoordinate+1]))
        {
            return true;
        }
        currentCoordinate+=2;
        coordinates[0] -- ;
    }
    return false;
}
}



int main()
{
    char c[3][3] = {'c','a', 't' , 'w' , 'h' , 'o' , 'w', 'i' , 'n'};
    char words[3][9];
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            std::cin>>words[i][j];
        }
    }

    std::cout<<crossword (c, words,3);
    return 0;
}