#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j) {
    // Base condition
    if (i >= j) {
        return 0;
    }

    int mn = INT_MAX;

    // Try every possible partition
    for (int k = i; k <= j - 1; k++) {
        int tempAns = solve(arr, i, k) +
                      solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j];

        mn = min(mn, tempAns);
    }
    return mn;
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications = "
         << solve(arr, 1, n - 1) << endl;

    return 0;
}
