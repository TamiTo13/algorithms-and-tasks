/* https://leetcode.com/problems/climbing-stairs/description/ */

#include <iostream>

class Solution {
    int dp[100000];
public:
    int climbStairs(int n) {
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        } 
        return dp[n];
    }
};

int main() {
    Solution a;
    std::cout<<a.climbStairs(10);
}