/*
Here when the array is sorted but they haven't given any clue 
that the array is ascending or descending order 
*/

#include<bits/stdc++.h>
using namespace std;

//ascending - 
int BSAsc(vector<int> &arr , int element){
    int start = 0;
    int end = arr.size() -1;

    while(start <= end){
        int mid = start + end -start/2;

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

//for descending order - 
int BSDesc(vector<int> &arr , int element){
    int start = 0;
    int end = arr.size() -1;

    while(start <= end){
        int mid = start + end -start/2;

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

int orderNotKnown(vector<int>&arr , int element){
    if(arr[0] < arr[1]){
        return BSAsc(arr , element);
    }else{
        return BSDesc(arr , element);
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int element = 5;

    cout << orderNotKnown(arr , element);
}