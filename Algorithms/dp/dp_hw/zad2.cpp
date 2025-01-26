#include <iostream>
#include <vector>

using namespace std;


int arr[64];
vector<vector<int>> path[2][64];
pair<bool,bool> dp[2][64];


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

    sum = Sum/2;

    dp[0]->first = true;
    dp[0]->second = true;
    for(int i = 0; i<n; i++)
    {
        for(int x = sum; x>=arr[i]; x--) {
            if(dp[x]->first) {
                //cout<<x<<" ";
                dp[x]->second = true;
            } else if(dp[x-arr[i]]->first) {
                dp[x]->first = true;
            }
        }
    }


    int max = 0;
    for(short i =1; i<=sum; ++i)
     {
        if(dp[i]->first && dp[i]->second) max =i;
        //cout<<dp[i]->first<<" "<<dp[i]->second;
     }

     //cout<<max<<" "<<Sum<<" ";
     cout<<"answer: "<<Sum - max*2;
}