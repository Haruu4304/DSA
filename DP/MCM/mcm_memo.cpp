/*
MCM Memorization technique - 
*/

#include<bits/stdc++.h>
using namespace std;

//global decaler
int t[1001][1001];

int solve(vector<int> &arr , int i , int j){
    //base cond.
    if(i >= j){
        return 0;
    }

    //if it is already solved
    if(t[i][j] != -1){
        return t[i][j];
    }

    //else
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempAns = solve(arr, i, k) +
                      solve(arr, k + 1, j) +
                      arr[i - 1] * arr[k] * arr[j];

        mn = min(tempAns , mn);
    }

    return t[i][j] = mn;
}

int matrixMultiplication(vector<int> &arr){
    int n = arr.size();
    memset(t , -1 , sizeof(t));
    return solve(arr , 1 , n-1);
}

int main(){
    vector<int> arr = {40 , 20 , 30 , 10  , 30};
    cout << matrixMultiplication(arr);
}