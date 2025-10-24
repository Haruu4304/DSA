/*
Problem statement : Frequency Sort
this problem can be solved using 3 methods -
1. heap
2. comparator
3. bin sort

now we are learning method 1 : heap
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int> &arr){
    int n = arr.size();

    //step 1 : create one map to store the frequencies
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    //step 2 : choose the which heap method you will use
    //so here i will use maxHeap because we want top frequencies first
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int , int>>> maxH;

    //step 3: put the values inside heap - key -> frequence and value -> arr[i]
    for(auto i=mp.begin(); i!=mp.end(); i++){
        maxH.push({i->second , i->first}); // ({frequency , arr[i]})
    }

    //step 4 : remove all the elements 
    vector<int> result;
    while(maxH.size() > 0){
        int freq = maxH.top().first;
        int element = maxH.top().second;

        for(int i=1; i<=freq; i++){
            result.push_back(element);
        }
        maxH.pop();
    }

    reverse(result.begin() , result.end());

    return result;
}

int main(){
    vector<int> arr = {1,1,1,3,2,2,4};

    vector<int> result = frequencySort(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
