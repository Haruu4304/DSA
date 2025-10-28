/*
Brute Force - O(n^2)
Next Greater element on left side
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NGEtoLeft(vector<int> &arr){
    int n = arr.size();
    //to store the result - 
    vector<int> result;

    for(int i=0; i<n; i++){
        int nextGreater = -1;
        for(int j=i-1; j>=0; j--){
            if(arr[i] < arr[j]){
                nextGreater = arr[j];
                break;
            }
        }
        result.push_back(nextGreater);
    }

    return result;
}

int main(){
    vector<int> arr = {1,3,2,4};

    vector<int> result = NGEtoLeft(arr);

    for(int value : result){
        cout << value << " ";
    }
}