/*
Problem statement : find upto kth largest element from an array
Explanation : if k = 2 then you have to return top most 2 large element 1. is the largest 
    2. will be 2nd largest
Example : Input: arr[] = [12, 5, 787, 1, 23], k = 2
          Output: [787, 23]
Identification : here they have given k and asking for largest -> heap
heap => min heap(largest)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> kthlargest(vector<int> &arr , int k){
    priority_queue<int, vector<int> , greater<int>> minH;
    int size = arr.size();

    for(int i=0; i<size; i++){
        minH.push(arr[i]);

        //the check the condition - 
        if(minH.size() > k){
            minH.pop();
        }
    }
    
    // Extract top k largest elements
    vector<int> result;
    while(!minH.empty()){
        result.push_back(minH.top());
        minH.pop();
    }

    //the result will stored in reverse
    reverse(result.begin() , result.end());

    return result;
}

int main(){
    vector<int> arr = {12, 5, 787, 1, 23};
    int k = 2;

    vector<int> ans = kthlargest(arr, k);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}