#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int progress[1001] = {1, };;

int MOD(int x) {
    return x < 0 ? -x : x;
}

int getOpposite(int x) {
    return x<0 ? 1:-1;
}

int main() {
    
    cin>>n;
    cin>>arr[0]>>arr[1];
    progress[0] = 1;
    progress[1] = (arr[0] - arr[1] < 0 ? - (progress[0] + 1) : progress[0] + 1);

    for(int i = 2; i<n; i++)
    {
        std::cin>>arr[i];
        for(int j = 0; j<i; j++) {
            if(arr[j] == arr[i]) {
                continue;
            }
            else if(getOpposite(arr[j]-arr[i]) != getOpposite(progress[j]) &&
                                     ( MOD(progress[i]) < MOD(progress[j]) ))
            {
                progress[i] = getOpposite(progress[j])*(MOD(progress[j]) + 1);
            }
        }
    }

     printf("%d", *std::max_element(progress, progress + n));

}