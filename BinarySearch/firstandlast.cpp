/*
First and last occurrence of an element - 
*/

#include<bits/stdc++.h>
using namespace std;

//for first occurrance - 
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

vector<int> searchRange(vector<int> arr , int target){
    vector<int> result;
    int a = FirstOccurrance(arr , target);
    int last = lastOccurrance(arr , target);
    result.push_back(a);
    result.push_back(last);

    return result;
}

int main(){
    vector<int> arr = {2 , 4 ,10 ,10 , 10 , 18 , 20};
    int search = 10;

    vector<int> result = searchRange(arr , search);

    for(auto val : result){
        cout << val << endl;
    }
}