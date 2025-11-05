/*
Implement Minimum Element in Stack with Extra Space
*/

#include<bits/stdc++.h>
using namespace std;

//global decaration - 
stack<int> s;
stack<int> ss;

void pushelement(int a){
    s.push(a);

    if(ss.top() >= a || ss.empty()){
        ss.push(s.top());
    }
}

int pop(){
    if(s.empty()){
        return -1;
    }
    int ans = s.top();
    s.pop();

    if(ss.top() == ans){
        ss.pop();
    }

    return ans;
}

int getMinElement(vector<int> arr){
    if(ss.empty()){
        return -1;
    }
    return ss.top();
}

int main(){
    vector<int> arr = {18,19,29,15,16};

    cout << getMinElement(arr);
}