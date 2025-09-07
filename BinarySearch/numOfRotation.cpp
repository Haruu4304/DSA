#include <bits/stdc++.h>
using namespace std;

int NumberOfRotation(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int N = arr.size();

    while (start <= end) {
        // case 1: if subarray is already sorted
        if (arr[start] <= arr[end]) {
            return start;  // minimum element at start
        }

        int mid = start + (end - start) / 2;
        int prev = (mid + N - 1) % N;
        int next = (mid + 1) % N;

        // case 2: check if arr[mid] is minimum
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid;
        }
        // case 3: left half sorted → go right
        else if (arr[start] <= arr[mid]) {
            start = mid + 1;
        }
        // case 4: right half sorted → go left
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> rotatedArray = {11, 12, 15, 18, 2, 5, 6, 8};
    cout << "Number of rotations = " << NumberOfRotation(rotatedArray);
}
