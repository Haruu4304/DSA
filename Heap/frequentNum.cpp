/*
Problem statement: Top k frequent numbers
Explanation : here you have given one array and you have to return the top array elements
whose frequence is greater then or equal to k.
Identification - Top and k -> min heap
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> topKFreq(vector<int> arr, int k){
    int n = arr.size();
    //first make the map
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    //now the main part - 
    priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int, int>>> minH;
    for(auto i=mp.begin(); i!= mp.end(); i++){
        minH.push({i->second, i->first}); // {frequency, arr[i]}

        if(minH.size() > k){
            minH.pop();
        }
    }

    vector<int> result;
    while(!minH.empty()){
        result.push_back(minH.top().second);
        minH.pop();
    }

    reverse(result.begin() , result.end());

    return result;
}

int main(){
    vector<int> arr = {3 ,1,4, 4, 5, 2, 6 ,1};
    int k = 2;
    vector<int> result = topKFreq(arr, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}