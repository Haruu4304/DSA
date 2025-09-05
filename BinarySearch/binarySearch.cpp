/*
Binary Search basic - 
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr , int element){
    int start = 0;
    int end = arr.size() -1;

    while(start <= end){
        int mid = start + end - start/2;
        if(element == arr[mid]){
            return mid;
        }else if(element < arr[mid]){
            end = mid -1;
        }else{
            start = mid+1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int element = 2;

    cout << binarySearch(arr , element);
}