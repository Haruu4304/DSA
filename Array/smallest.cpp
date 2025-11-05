/*
Problem Statement : Find the smallest element in an array.
*/

//brute force method - 
#include<bits/stdc++.h>
using namespace std;
//time complexity -> O(n)
int smallestElement(vector<int> &arr){
    int mn = 0;
    for(int i=0; i<arr.size(); i++){
        mn = min(mn , arr[i]);
    }
    return mn;
}

int main(){
    vector<int> arr = {2,5,1,9,7,0,15,17};

    cout << smallestElement(arr);
}