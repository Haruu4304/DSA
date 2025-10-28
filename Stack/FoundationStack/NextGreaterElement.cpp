/*
This Code is optimization of previous brute force on - NextLargestElementBF.cpp
here we are using Stack 
why ?  -> i) array ii) brute(j is dependent on i)
tc -> O(n);
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
    int  n = arr.size();
    vector<int> v; //to store the result
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        //cond1 : stack is empty
        if(s.size() == 0){
            v.push_back(-1);
        }else if(s.size() > 0 && s.top() > arr[i]){ //cond2 : when the top is greater
            v.push_back(s.top());
        }else{
            //pop the elements from stack
            while(s.size() > 0 && s.top() <= arr[i]){
                s.pop();
            }
            // if(s.size() == 0){
            //     v.push_back(-1);
            if(s.top() > arr[i]){
                v.push_back(s.top());
            }
        }
        //push in stack
        s.push(arr[i]);
    }
    //at the last reverse the vector
    reverse(v.begin() , v.end());
    return v;
}

int main(){
    vector<int> arr = {1,3,2,4};
    vector<int> result = nextLargerElement(arr);

    for(int value : result){
        cout << value << " ";
    }

    cout << endl;
}