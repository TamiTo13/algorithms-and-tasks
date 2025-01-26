// 1 -> А, 2->B... 26 -> Z и имаме няква поредица от числа (примерно 1231241),
// където трябва да изведем броя на всички възможни стрингове

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') dp[i]=0;
            else {
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) 
                                                        dp[i]+=dp[i+2];
            }
        }
        return s.empty()? 0 : dp[0];   
    }
};