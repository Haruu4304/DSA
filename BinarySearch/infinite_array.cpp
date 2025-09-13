/*
Problem Statement - 
Find an element in Infinite Sorted Array - 
*/

#include<bits/stdc++.h>
using namespace std;

//normal Binary Search 
int BS(vector<int> arr , int start , int end , int key){
    while(start <= end){
        int mid = start + (end - start)/2;

        if(key == arr[mid]){
            return mid;
        }else if(key > arr[mid]){
            start = mid+1;
        }else if(key < arr[mid]){
            end = mid-1;
        }
    }
}

int findInfiniteElement(vector<int> arr, int key){
    //basic initialization
    int start = 0;
    int end = 1; //because this array is endless that's why

    while(key > arr[end]){
        start = end;
        end = end * 2;
    }

    int result = BS(arr, start , end , key);

    return result;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int key = 14;

    cout << findInfiniteElement(arr, key);
}