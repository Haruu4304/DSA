/*
Problem Statement - 
Find Floor element from the sorted array.

hint -> find the greatest element but smaller than element.
*/

#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr , int x){
    int start = 0, end = arr.size() - 1;
    int res = -1;  // if no floor exists

     while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == x) {
                res = mid;       // store index
                start = mid + 1; // go right to find last occurrence
            } 
            else if (arr[mid] < x) {
                res = mid;       // possible floor
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
    return res;
}

int main(){
    vector<int> arr = {1,2,8,10,10,12,19};

    int x = 5;

    cout << findFloor(arr , x);
}