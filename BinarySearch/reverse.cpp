/*
Here we are doing binary search on desecending order - 
*/

#include<bits/stdc++.h>
using namespace std;

int BinaryReverse(vector<int> &arr , int element){
    int start = 0;
    int end = arr.size() -1;

    while(start <= end){
        int mid = start + end-start/2;
        if(element == arr[mid]){
            return mid;
        }else if(element < arr[mid]){
            start = mid+1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {20,17,15,10,3,4};
    int element = 4;

    cout << BinaryReverse(arr , element);
}