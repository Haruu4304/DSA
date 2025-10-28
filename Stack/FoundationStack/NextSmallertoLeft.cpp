/*
This is optimizied version of - 
Next Smaller element on left side - 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallerToLeft(vector<int> &arr){
    int n = arr.size();
    vector<int> result;
    stack <int> s;

    //to check on left side we will go in normal way only
    for(int i=0; i<n; i++){
        if(s.empty()){
            result.push_back(-1);
        }else if(!s.empty() && s.top() < arr[i]){
            result.push_back(s.top());
        }else{
            while(s.size() > 0 && s.top() >= arr[i]){
                s.pop();
            }

            if(s.empty()){
                result.push_back(-1);
            }else{
                result.push_back(s.top());
            }
        }

        s.push(arr[i]);
    }

    return result;
}

int main(){
    vector<int> arr = {1,3,2,4};

    vector<int> result = NextSmallerToLeft(arr);

    for(int value : result){
        cout<< value << " ";
    }
}