/*
Problem Statement : Peak Element (Unsorted Array)
the element is greater then its left neighbour as well as greater than its right neighbour
*/

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums){
    int start = 0;
    int end = nums.size()-1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(mid > 0 && mid < nums.size()-1){ //that means my mid lies in between the array
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){ //peak on mid check
                return mid; //return its index
            }else if(nums[mid] < nums[mid-1]){ //when mid is not peak elem then check the left and right
                //part and left is greater then check on left side
                end = mid-1;
            }else{
                //if right side is greater then go on right side
                start = mid+1;
            }
        }else if(mid == 0){ //if mid is on 0th index
            //then check only its right neighbour
            if(nums[mid] > nums[mid+1]){
                return 0;
            }else{
                return 1;
            }
        }else if(mid == nums.size()-1){//when my mid is on another end of array
            //then check its left part only
            int numsSize = nums.size()-1;
            if(nums[numsSize] > nums[numsSize-1]){
                return numsSize;
            }else{
                return numsSize-1;
            }
        }

    }
    //if nothing is their then return 
    return -1;
}

int main(){
    vector<int> nums = {5,10,20,15};

    cout << findPeakElement(nums);
}