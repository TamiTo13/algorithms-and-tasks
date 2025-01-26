#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int arr[64];
//vector<vector<int>> path[2][64];
int dp[64][1000];




int main() {
    int n,sum,Sum;
    int returnVal = 0;
    Sum = 0;
    cin>>n;
    for(short i =0; i<n; ++i)
    {   
        cin>>arr[i];
        Sum +=arr[i];
    }

    fill(dp[0], dp[0]+1001, -1);
    //for(int i=0; i<64;i++) {
      //  for(int k=0; k<1000; k++) {
     //       std::cout<<dp[i][k]<<" ";
     //   }
    //    cout<<endl;
    //}

    sum = Sum/2;    
    
    dp[0][0] = 0;
    dp[0][arr[0]] = arr[0];
    for(int i = 1; i<n; i++)
    {
        for(int k = 0; k<1000; k++) {
            /*if(dp[i-1][k] == -1) {
                continue;
            } */
            dp[i][k] = max(max(dp[i-1][k], arr[i] + dp[i-1][arr[i]+k]),arr[i] + dp[i-1][k-arr[i]]);
        }
    }

     //out<<max<<" "<<Sum<<" ";
   /* for(int i=0; i<5;i++) {
      for(int k=0; k<20; k++) {3
           std::cout<<dp[i][k]<<" ";
      }
       cout<<endl;
    } */
     cout<<Sum-dp[n-1][0];
}