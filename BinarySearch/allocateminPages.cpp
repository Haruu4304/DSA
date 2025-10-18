/*
PS : 
*/

#include<bits/stdc++.h>
using namespace std;

int startArray(vector<int>&arr , int n){
    int max = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int sumArray(vector<int>&arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    return sum;
}

bool isValid(vector<int>&arr , int n , int k , int mx){
    int student = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
        if(sum > mx){
            student++;
            sum = arr[i];
        }

         if (student > k) {
            return false;
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k){
    int n = arr.size();
    int start = startArray(arr , n);
    int end = sumArray(arr , n);
    int result = -1;

    //main condition - 
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isValid(arr, n , k , mid) == true){
            result = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return result;
}


int main(){
    vector<int> arr = {10,20,30,40};
    int k = 2;

    cout << findPages(arr,k);
}