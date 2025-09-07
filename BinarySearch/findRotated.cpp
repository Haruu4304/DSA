/*
Problem Statement - 
find the element in sorted rotated array - 
*/

#include<bits/stdc++.h>
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

//general Binary Search logic - 
int BS(vector<int> &arr , int start , int end , int element){
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == element){
            return mid;
        }else if(element < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}


int foundelem(vector<int> arr, int element){
    int start = 0;
    int end = arr.size()-1;

    //it will return the min element index from rotated sorted array
    int index = NumberOfRotation(arr);

    int left = BS(arr , start , index-1 , element);//it will check the half of 1st part 
    int right = BS(arr , index , end , element); //2nd part will checked 

    if(left != -1){
        return left;
    }else{
        return right;
    }
}

int main(){
    vector<int> arr = {11,12,15,18,2,5,6,8};
    int element = 15;

    cout << foundelem(arr , element);
}