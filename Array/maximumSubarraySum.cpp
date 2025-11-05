/*
Kadane algorithm
*/

#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr) {
    int n = arr.size();
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        currSum += arr[i];

        if(currSum > maxSum)
            maxSum = currSum;

        if(currSum < 0)
            currSum = 0;  // reset if negative
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1 ,2 ,3 ,-2, 5};
    cout << maxSum(arr);
}