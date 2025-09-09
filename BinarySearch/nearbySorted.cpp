/*
Problem Statement - 
Find an element from nearly sorted array : 
*/

#include<bits/stdc++.h>
using namespace std;

int findTarget(vector<int> &arr , int target){
    //basic BS - 
    int start = 0;
    int end = arr.size() -1;

    while(start <= end){
        int mid = start + end - start/2;

        if(target == arr[mid]){ //if an element is on (i)
            return mid;
        }else if(target == arr[mid-1]){ //if the element is on (i-1)
            return mid-1;
        }else if(target == arr[mid+1]){//if an element is on(i+1)
            return mid+1;
        }else if(target < arr[mid]){
            end = mid-2;//because we already checked (mid-1)
        }else if(target > arr[mid]){
            start = mid+2;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {5,10,30,20,40};
    int target = 20;

    cout << findTarget(arr, target);
}