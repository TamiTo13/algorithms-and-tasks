#include <iostream>
#include <cstdio>

using namespace std;

long long  dp[100000];
int arr[100000];

int main() {
    int n;
    bool three = true;

    cin>>n;

    for(int i =0; i<n;i++) {
        cin>>arr[i];
    }


    if(arr[0] >= 0) 
    {
        dp[0] = arr[0]*3;
        three = false;
    }
    else dp[0] = arr[0]*2;

    if(arr[1] >= 0 && arr[1] > arr[0]) 
    {
        dp[1] = arr[0] * 2 + arr[1] * 3;
        three = false;
    }
    else 
    {
        dp[1] = dp[0] + arr[1]*2;
        three = true;
    }

    for(int i =2; i<n; i++)
    {
        if(arr[i] < 0) {
            dp[i] = dp[i-1] + arr[i]*2;
            three = true;
        }
        else {
            if(three) {
                dp[i] = dp[i-1] + arr[i]*3;
                three = false;
            }
            else if(dp[i-1] + arr[i]*2 < dp[i-2] + arr[i-1]*2 + arr[i]*3) {
                dp[i] = dp[i-2] + arr[i-1]*2 + arr[i]*3;
                three = false;
            }
            else
            {
                dp[i] = dp[i-1] + arr[i]*2;
            }
        }
    }

    for(int i = 0; i<n ; i++) {
        std::cout<<dp[i]<<" ";
    }

}