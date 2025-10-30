/*
Problem Statement : Stock Span Problem
meaning : you have to count the consecutive smaller or equal to element on left side

this problem is very much similar with nearest greater element on left
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> StockSpanProblem(vector<int> &arr){
    int n = arr.size();
    vector<int> v; //to store the index of greater element 
    vector<int> result; //to store the final result in it4
    //first -> to store the element (sort), second -> index of that element
    stack<pair<int , int>> s; 
    //to check on left side - 
    for(int i=0; i<n; i++){
        if(s.empty()){
            v.push_back(-1);
        }else if(s.size() > 0 && s.top().first > arr[i]){
            v.push_back(s.top().second);
        }else{
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }

            if(s.empty()){
                v.push_back(-1);
            }else{
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i] , i}); //element , index
    }

    //output -> v[i] - i;
    for(int i=0; i<v.size(); i++){
        result.push_back(i - v[i]);
    }

    return result;
}

int main(){
    vector<int> arr = {100,80,60,70,60,75,85};

    vector<int> result = StockSpanProblem(arr);

    for(int value : result){
        cout << value << " ";
    }
}