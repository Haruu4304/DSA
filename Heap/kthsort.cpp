/*
PS:sort k sorted array / nearly sorted array.

what does mean of nearly sorted ?
on index 0 element will present in k length from forward or backward.

here heap will applicable -> min heap (smallest element will )
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> kthsort(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minH;
    vector<int> result;

    int size = arr.size();

    // Step 1: push first k+1 elements
    for (int i = 0; i <= k && i < size; i++) {
        minH.push(arr[i]);
    }

    // Step 2: for remaining elements
    for (int i = k + 1; i < size; i++) {
        result.push_back(minH.top());
        minH.pop();
        minH.push(arr[i]);
    }

    // Step 3: empty the heap
    while (!minH.empty()) {
        result.push_back(minH.top());
        minH.pop();
    }

    return result;
}

int main(){
    vector<int> arr = {6,5,3,2,8,10,9};
    int k = 3;

    vector<int> result = kthsort(arr, k);

    for(int val : result){
        cout << val << " ";
    }
}