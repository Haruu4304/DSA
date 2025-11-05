/*
Problem Statement : Find the largest element in an array.
*/

//brute force method - 
#include<bits/stdc++.h>
using namespace std;
//time complexity -> O(n)
int largestElement(vector<int> &arr){
    int mx = 0;
    for(int i=0; i<arr.size(); i++){
        mx = max(mx , arr[i]);
    }
    return mx;
}

int main(){
    vector<int> arr = {2,5,1,9,7,0,15,17};

    cout << largestElement(arr);
}