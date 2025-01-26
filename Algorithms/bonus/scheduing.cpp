/*https://judge.openfmi.net/practice/get_problem_description?contest_id=175&problem_id=543*/

#include <cstdio>
#include <algorithm>

int s, e;
std::pair<int, int> arr[1000000];

void sollution() {
    int i = 0;
    // Note that arr[i].second is the start time and arr[i].first is the end time
    while (scanf("%d %d", &arr[i].second, &arr[i].first) != EOF)
    {
        arr[i].first += arr[i].second;
        ++i;
    }


    std::sort(arr, arr + i); 
    int returnVal = 0, last = -1;
    for (int j = 0; j < i; ++j)
    {
        if (arr[j].second >= last)
        {
            returnVal++;
            last = arr[j].first;
        }
    }
  
    printf("%d\n", returnVal);
}

int main() {
    sollution();
    return 0;
}