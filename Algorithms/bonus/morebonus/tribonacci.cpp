//https://leetcode.com/problems/n-th-tribonacci-number/

long long dp[3];


class Solution {
public:
    int tribonacci(int n) {
        dp[0] = 0; 
        dp[1] = 1; 
        dp[2] = 1;

        for(int i = 3; i<=n;i++) {
            dp[i%3] += dp[(i+1)%3] + dp[(i+2)%3];
        }

        return dp[n%3];
    }
};