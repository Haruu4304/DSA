/*
Problem Statement : Connect Ropes to Minimize the Cost.
min heap
we will pop fist two elements make their sum and push inside the heap
and add the sum in tCost;


One correction is their - 
with this code it may give you time limit exceed error
so instead of using int you should use long long 
*/

#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr){
    int n = arr.size();
    //step 1: declare min heap
    priority_queue<int , vector<int> , greater<int>> minH;

    //step 2 : push elements in heap
    for(int i=0; i<n; i++){
        minH.push(arr[i]);
    }

    //step 3 : now remove the top 2 element and add in tCost;
    int sum = 0;
    int tCost = 0;
    while(minH.size() > 1){
        int firstElem = minH.top();
        minH.pop();
        int secondElem = minH.top();
        minH.pop();
        sum = firstElem + secondElem;
        tCost = tCost + sum;
        minH.push(sum);
    }

    return tCost;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    cout << minCost(arr);
}