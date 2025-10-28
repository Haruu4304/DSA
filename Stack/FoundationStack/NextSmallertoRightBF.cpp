/*
here we are trying to find the smallest the element on right side of an array.
brute force approach - O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallertoRight(vector<int> &arr){
    int n = arr.size();
    vector<int> result;

    for(int i=0; i<n; i++){
        int nextSmaller = -1;
        for(int j = i+1; j<n; j++){
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
    vector<int> arr = {4,5,2,10,3};

    vector<int> result = NextSmallertoRight(arr);

    for(int value : result){
        cout << value << " ";
    }
}