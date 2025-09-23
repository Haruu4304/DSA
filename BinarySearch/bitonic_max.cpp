/*
Problem Statement : find the max element in bitonic array.

(This problem is very much similar to Peak element problem)
*/

#include<bits/stdc++.h>
using namespace std;

int maxElementBitonic(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int mid = start + (end-start)/2;
        //base condition - 
        if(mid > 0 && mid < arr.size()-1){
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return arr[mid];
            }else if(arr[mid] < arr[mid-1]){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }else if(mid == 0){
            if(arr[mid] > arr[mid+1]){
                return arr[mid];
            }else {
                return arr[mid+1];
            }
        }else if(mid == arr.size()-1){
            if(arr[mid] > arr[mid-1]){
                return arr[mid];
            }else{
                return arr[mid-1];
            }
        }   
    }
    return -1;
}

int main(){
    vector<int> arr = {1,3,8,12,4,2};

    cout << maxElementBitonic(arr);
}