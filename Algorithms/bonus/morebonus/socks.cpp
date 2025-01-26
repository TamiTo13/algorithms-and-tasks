//https://action.informatika.bg/problems/226

#include <algorithm>
#include <cstdio>
#include <iostream>

int arr[100002];
int p;
int n;

bool check(int x)
{
    int j = 0;
    for (int i = 1; i < n && j < p; ++i)
    {
        if (arr[i] - arr[i-1] <= x)
        {
            ++j;
            ++i;
        }
    }

    return j == p;
}

void solve() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);

    int l = 0, r = 1000000000;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (check(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d", l);
}


int main()
{
    solve();
    return 0;
}