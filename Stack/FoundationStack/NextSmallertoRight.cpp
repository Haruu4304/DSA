/*
This is my optimized question - 
time complexity -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallertoRight(vector<int> &arr){
    int  n = arr.size();
    vector<int> v; //to store the result
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        //cond1 : stack is empty
        if(s.size() == 0){
            v.push_back(-1);
        }else if(s.size() > 0 && s.top() < arr[i]){ //cond2 : when the top is smaller
            v.push_back(s.top());
        }else{
            //pop the elements from stack
            while(s.size() > 0 && s.top() >= arr[i]){
                s.pop();
            }
            
            if(s.top() < arr[i]){
                v.push_back(s.top());
            }else{
                v.push_back(-1);
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
    vector<int> arr = {4,5,2,10,3};

    vector<int> result = NextSmallertoRight(arr);

    for(int value : result){
        cout << value << " ";
    }
}