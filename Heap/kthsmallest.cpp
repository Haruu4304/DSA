/*
Problem statement : find the kth smallest element from an array
identification : here they given k and said to find smallest -> Heap
in heap -> smalles = max heap
*/

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    //step 1 : declare max heap
    priority_queue<int> maxH;
    int size = arr.size();

    for(int i=0; i<size; i++){
        maxH.push(arr[i]);

        //check the condition
        if(maxH.size() > k){
            maxH.pop();
        }
    }

    //at every time the result is on top
    return maxH.top();
}

int main(){
    vector<int> arr = {7,10,4,3,20,15};
    int k = 3;

    cout << kthSmallest(arr,k);
}