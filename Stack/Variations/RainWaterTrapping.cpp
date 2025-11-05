/*
Problem Statement : Rain Water Trapping
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height){
    int n = height.size();
    if(n == 0) return 0;

    int mxL[n], mxR[n];

    // Compute max on left
    mxL[0] = height[0];
    for(int i=1; i<n; i++){
        mxL[i] = max(mxL[i-1], height[i]);
    }

    // Compute max on right
    mxR[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        mxR[i] = max(mxR[i+1], height[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += min(mxL[i], mxR[i]) - height[i];
    }

    return ans;
}

int main(){
    vector<int> height = {3,0,0,2,0,4};
    cout << trap(height);
}
