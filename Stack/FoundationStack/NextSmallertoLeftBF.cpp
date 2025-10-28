/*
Brute force method -
Next Smaller element on left side - 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallertoLeft(vector<int> &arr){
    int n = arr.size();
    //to store the result - 
    vector<int> result;

    for(int i=0; i<n; i++){
        int nextSmaller = -1;
        for(int j=i-1; j>=0; j--){
            if(arr[i] > arr[j]){
                nextSmaller = arr[j];
                break;
            }
        }
        result.push_back(nextSmaller);
    }

    return result;
}

int main(){
    vector<int> arr = {1,3,2,4};

    vector<int> result = NextSmallertoLeft(arr);

    for(int value : result){
        cout << value << " ";
    }
}