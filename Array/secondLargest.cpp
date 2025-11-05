/*
Given an array of positive integers arr[], return the second largest element from the array. 
If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.
*/
#include<bits/stdc++.h>
using namespace std;
//time complexity -> O(n)
int getSecondLargest(vector<int> &arr){
    int n = arr.size();
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }

        if(arr[i] > secondLargest && arr[i]!=largest){
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN){
        return -1;
    }else{
        return secondLargest;
    }
}

int main(){
    vector<int> arr = {12,35,1,10,34,1};

    cout << getSecondLargest(arr);
}