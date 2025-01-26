#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_length = 3*(1e5);
const int MODUL = 7+1e9;

int dp[100000];

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
    int buf = 0;
    int cnt = 1;
    bool in = false;

    while(word[i]) {

        if( (word[i] == 'u' && word[i+1] == 'u' )) {
            buf = 0;
            in = true;
            while(word[i] == 'u' ) {
                buf++;
                i++;
            }
            cnt *= solve(buf);
        } 
        else if( (word[i] == 'n' && word[i+1] == 'n' )) {
            buf = 0;
            in = true;
            while(word[i] == 'n' ) {
                buf++;
                i++;
            }
            cnt *= solve(buf);
        }
        if(!in) i++;
        else in = false;
    }

    return cnt;
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
    std::cout<<(calculate(word) % MODUL);
    return 0;

}