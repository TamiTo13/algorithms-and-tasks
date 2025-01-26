//https://action.informatika.bg/problems/117


#include <cstdio>


long long int n;
long long f;
long long fSum;

long long int sumK(long long int k)
{
    return (((f+k)*(f+k-1)) / 2LL) - fSum;
}

void solve() {
    scanf("%lld %lld", &n, &f);
    fSum = (f*(f-1)) / 2LL;
    
    long long int left = 0, right = 50002032;
    while (left <= right)
    {
        long long int mid = left + (right - left) / 2;
        if (sumK(mid) >= n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%lld", right + 1);
}


int main()
{
    solve();
    return 0;
}