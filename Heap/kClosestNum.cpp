/*
Problem statement : K closest numbers
here in this question they have given you two things
X and K 
X -> it will used to check which element 
and K -> find that X value for k numbers.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> kclosestNumber(vector<int> &arr, int k, int x){
    //declare max heap - 
    priority_queue<pair<int, int>> maxH;
    int size = arr.size();

    for(int i=0; i<size; i++){
        maxH.push({abs(arr[i] - x) , arr[i]});

        if(maxH.size() > k){
            maxH.pop();
        }
    }

    vector<int> result;
    while (!maxH.empty()) {
        result.push_back(maxH.top().second);
        maxH.pop();
    }

    return result;
}

int main(){
    vector<int> arr = {5,6,7,8,9};
    int k = 3;
    int x = 7;

    vector<int> result = kclosestNumber(arr, k, x);

    sort(result.begin(), result.end());

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}