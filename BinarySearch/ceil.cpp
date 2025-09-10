#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int> arr , int x){
    int start = 0;
    int end = arr.size()-1;
    int res  = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(x == arr[mid]){
            res = mid;
            end = mid -1;
        }else if(x < arr[mid]){
            res = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,8,10,11,12,19};
    int x = 5;

    cout << findCeil(arr , x);
}