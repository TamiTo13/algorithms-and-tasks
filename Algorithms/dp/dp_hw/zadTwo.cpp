#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int minimumSubtraction(vector<int>& numbers) {
    int totalSum = 0;
    int n = numbers.size();

    // Calculate the total sum of all numbers
    for (int num : numbers) {
        totalSum += num;
    }

    // Initialize the dynamic programming table
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Base case: When sum is 0, it is always possible to divide the remaining numbers
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dynamic programming table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            // If the current number can be included in the sum
            if (numbers[i - 1] <= j) {
                // Two possibilities: include the number or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - numbers[i - 1]];
            } else {
                // Exclude the number
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Find the minimum difference
    int minDifference = INT_MAX;
    for (int j = floor(totalSum / 2.0); j >= 0; j--) {
        if (dp[n][j]) {
            minDifference = totalSum - 2 * j;
            break;
        }
    }

    return minDifference;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the positive integers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int minSubtraction = minimumSubtraction(numbers);
    cout << "Minimum quantity to subtract: " << minSubtraction << endl;

    return 0;
}







