/*
Problem Statement : Maximum Area Histogram
here they have given one array which indicate - height of building
*/

#include<bits/stdc++.h>
using namespace std;

//Nearest Smaller on left, output -> index of smaller elements vector
vector<int> NSL(vector<int> &heights){
    int n = heights.size();
    //first will store the element and second will store its index
    stack<pair<int, int>> s;
    int pseudo = -1;
    vector<int> result;

    for(int i=0; i<n; i++){
        if(s.empty()){
            result.push_back(pseudo);
        }else if(!s.empty() && s.top().first < heights[i]){
            result.push_back(s.top().second);
        }else{
            while(s.size() > 0 && s.top().first >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                result.push_back(pseudo);
            }else{
                result.push_back(s.top().second);
            }
        }

        s.push({heights[i] , i});
    }

    return result;
}

//now to get the smaller height index on right side - 
vector<int> NSR(vector<int> &heights) {
    int n = heights.size();
    stack<pair<int, int>> s;
    vector<int> v;
    int pseudo = n;

    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            v.push_back(pseudo);
        } else if (s.top().first < heights[i]) {
            v.push_back(s.top().second);
        } else {
            while (!s.empty() && s.top().first >= heights[i]) {
                s.pop();
            }

            // ✅ FIX: must check if stack became empty
            if (s.empty()) {
                v.push_back(pseudo);
            } else {
                v.push_back(s.top().second);
            }
        }

        s.push({heights[i], i});
    }

    reverse(v.begin(), v.end());
    return v;
}


int largestRectangleArea(vector<int> &heights){
    int n = heights.size();
    vector<int> left = NSL(heights);
    vector<int> right = NSR(heights);

    //width = right[i] - left[i] - 1
    vector<int> width;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        ans = max(ans, width * heights[i]);
    }
    return ans;
}

int main(){
    vector<int> heights = {6,2,5,4,5,1,6};

    cout << largestRectangleArea(heights);
}