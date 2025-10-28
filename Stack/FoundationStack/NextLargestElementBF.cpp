/*
Next Greatest Element (aka) Nearest Greatest To Right.
Problem Explanation - 
Brute Force - O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> BFNGR(vector<int> &arr){
    int n = arr.size();
    vector<int> result;
    for(int i=0; i<n; i++){
        int nextGreater = -1;

        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                nextGreater = arr[j];
                break; //no more check further
            }
        }
        result.push_back(nextGreater);
    }
    return result;
}

int main(){
    vector<int> arr = {1,3,2,4};

    vector<int> result = BFNGR(arr);

    for(int value : result){
        cout << value << " ";
    }
    cout << endl;
}