/*
Search in bitonic array - 
in output you have to return the index of seach element 
if no element is found then just return the -1.
*/

#include <bits/stdc++.h>
using namespace std;

// Ascending order binary search
int BS(vector<int> &arr, int start, int end, int element) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// Descending order binary search
int BSDEC(vector<int> &arr, int start, int end, int element) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// Search in bitonic array
int searchBitonic(vector<int> &arr, int key) {
    int start = 0, end = arr.size() - 1;

    // Step 1: Find the peak element index
    int peak = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < arr.size() - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                peak = mid;
                break;
            } else if (arr[mid - 1] > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if (mid == 0) {
            peak = (arr[0] > arr[1]) ? 0 : 1;
            break;
        } else if (mid == arr.size() - 1) {
            peak = (arr[arr.size() - 1] > arr[arr.size() - 2]) ? arr.size() - 1 : arr.size() - 2;
            break;
        }
    }

    // Step 2: Search in both halves
    int asc = BS(arr, 0, peak, key);
    int desc = BSDEC(arr, peak + 1, arr.size() - 1, key);

    // Step 3: Return final answer
    if (asc != -1)
        return asc;
    else if (desc != -1)
        return desc;
    else
        return -1;
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};
    cout << searchBitonic(arr, 4); // Output: 4 (index of 4)
    return 0;
}
