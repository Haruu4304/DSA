/*
Problem Statement - 
Reverse an given array
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> &arr){
    int n = arr.size();
    vector<int> result;
    for(int i=n-1; i>=0; i--){
        result.push_back(arr[i]);
    }
    return result;
}

//reverse an array with the same array replace
void reverseArray(vector<int> &arr){
    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start < end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}

int main(){
    vector<int> arr = {2,3,5,6,7,0,12,4,8};

    reverseArray(arr);

    for(int value : arr){
        cout << value << " ";
    }
    cout << endl;
}