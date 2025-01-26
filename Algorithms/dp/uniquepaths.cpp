#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int matrix[1000][1000];
int dp[1000][1000];

int uniquePaths(int n, int m) {
    dp[0][0] = matrix[0][0];
    dp[0][1] = matrix[0][0] + matrix[0][1];
    dp[1][1] = matrix[0][0] + matrix[1][1];

    for(int j = 2; j<m;j++) {
        for(int i=0; i<=j; i++) {
            //dp[i][0] = matrix[i][0];
            if(i == 0) {
                dp[i][j] = min(dp[i][j-1], dp[i+1][j-1]) + matrix[i][j];
            }
            else if(i == j) {
                dp[i][j] = dp[i-1][j-1] + matrix[i][j];
            }
            else if(i == j-1) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + matrix[i][j];
            }
            else {
                dp[i][j] = min(min(dp[i][j-1],dp[i+1][j-1]),dp[i-1][j-1]) + matrix[i][j];
            }
            
        }
    }
        //std::cout<<matrix[n][i];
    int min = dp[0][m-1];
    for(int i = 1; i<n; i++)
    {
        if(min > dp[i][m-1]) {
            min = dp[i][m-1];
        }
    }
    return min;
}

void printF(int n, int m) {
     for(int i=0; i<n; i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

void init(int n, int m) {
    for(int i = 0; i<n; i++) {
        for(int j = 0; j <m; j++) {
            cin>>matrix[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>m>>n;
    init(m,n);

    
    std::cout<<uniquePaths(m,n);
    printF(m, n);
    
    return 0;
}