/*
Problem Statement : 
find the first occurrence of 1 in infinte binary sorted array.
Binary -> 0/1
ex., 00000000111111
*/

#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> arr, int start , int end){
    int res = -1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == 1){
            res = mid;
            end = mid-1;
        }else if(arr[mid] < 1){ //if it is like ke  0 < 1
            start = mid+1;
        }
    }
    return res;
}

int firstOcc(vector<int> arr){
    int start = 0;
    int end = 1;
    while(1 > arr[end]){
        start = end;
        end = end*2;
    }

    int result = BS(arr , start , end); //from here we will get start and end
    return result;
}

int main(){
    vector<int> arr = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1};
    cout << firstOcc(arr);
}