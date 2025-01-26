#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_length = 3*(1e5) + 5;
const long long MODUL = 7+1e9;

long long dp[MAX_length];

int solve(int n) {
    dp[0] = 1;
    dp[1] = 1;
    for (int x = 2; x <= n; x++)
    {
        dp[x] = dp[x-1] + dp[x-2];
        dp[x] %= MODUL;
    }

    return dp[n];
}


int calculate(char word[MAX_length]) {
    int i = 0;
    long long buf = 0;
    long long cnt = 1;

    while(word[i]) {

        if( (word[i] == 'u' && word[i+1] == 'u' )) {
            buf = 0;

            while(word[i] == 'u' ) {
                buf++;
                i++;
            }
            cnt *= solve(buf);
            cnt %= MODUL;
        } 
        else if( (word[i] == 'n' && word[i+1] == 'n' )) {
            buf = 0;

            while(word[i] == 'n' ) {
                buf++;
                i++;
            }
            cnt *= solve(buf);
            cnt %= MODUL;
        }
        else
        {
            i++;

        }
    }

    return cnt%MODUL;
}



int main() {
    //std::cout<<"dassdasd";

    char word[MAX_length];
    cin.getline(word, MAX_length);
    int i = 0;
    while (word[i++]) {
        if(word[i] == 'm' || word[i] == 'w' || !word[0]) {
            std::cout<<"0";
            return 0;
        }
    }
    //std::cout<<"dasda";
    std::cout<<(calculate(word));
    return 0;

}