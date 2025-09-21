/*
Problem Statement : Find the minimum difference in sorted array
*/

#include<bits/stdc++.h>
using namespace std;

int minDifference(vector<int>&arr, int key){
    int start = 0;
    int end = arr.size()-1;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(key == arr[mid]){
            return arr[mid];
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    int startms = abs(arr[start] - key);
    int endms = abs(arr[end]-key);

    if(startms < endms){
        return arr[start];
    }else{
        return arr[end];
    }
}

int main(){
    vector<int> arr = {1,3,8,10,15};
    int key = 12;

    cout << minDifference(arr,key)<<endl;
}