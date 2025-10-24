/*
method II - Comparator 
in this i am using lambda function to sort the array of frequencies
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int> &nums){
    int n = nums.size();
    //step 1: map
    unordered_map<int , int> mp;
    for(int i=0; i<n; i++){
        mp[nums[i]]++;
    }

    // Step 2: Sort using a lambda comparator
    auto mylambda = [&mp](int a, int b) {
        if (mp[a] == mp[b])
            return a > b;       // If same frequency, larger number first
        return mp[a] < mp[b];   // Lower frequency first
    };

    sort(begin(nums) , end(nums) , mylambda);

    return nums;

}


int main(){
    vector<int> nums = {1,1,2,2,2,3};

    vector<int> result = frequencySort(nums);

    for(auto value : result){
        cout << value << " ";
    }
    cout << endl;
}