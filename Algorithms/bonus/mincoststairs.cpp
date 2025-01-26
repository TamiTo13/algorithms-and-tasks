#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int dp[100000];

public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t n = cost.size();
        if(n <= 2) {
            return n==2 ? 
                min(cost[0], cost[1]) : cost[0]; 
        }
        cost[n] = 0; //floor
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i<=n;i++) {
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return dp[n];
    }
};

int main() {
    vector<int> test = {10,15,20};
    Solution a;
    cout<<a.minCostClimbingStairs(test);
}