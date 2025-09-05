/*
Count of an element in a sorted array - 
*/

#include<bits/stdc++.h>
using namespace std;

int FirstOccurrance(vector<int> arr , int target){
    int start = 0;
    int end = arr.size()-1;
    int res = -1;
    while(start <= end){
        int mid = start + end-start/2;
        if(target == arr[mid]){
            res = mid;
            end = mid-1;
        }else if(target < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}

//for last occurrance -
int lastOccurrance(vector<int>&arr , int target){
    int start = 0;
    int end = arr.size()-1;
    int res = -1;
    while(start <= end){
        int mid = start + end-start/2;
        if(target == arr[mid]){
            res = mid;
            start = mid+1;
        }else if(target < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}

int countFreq(vector<int>&arr , int target){
    int a = FirstOccurrance(arr , target);
    int b = lastOccurrance(arr , target);

    return (b-a+1);
}

int main(){
    vector<int>arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;

    cout << countFreq(arr , target);
}