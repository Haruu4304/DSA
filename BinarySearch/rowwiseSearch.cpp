/*
Problem statement : 
Search in row wise and column wise of sorted array - 

return the bool 
if the element is found then return true else return false;
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1; // start from top-right corner


    //bound condition - 
    while(i>=0 && i<n && j>=0 && j<m){
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] > target){
            j--;
        }else if(matrix[i][j] < target){
            i++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
};

    cout << searchMatrix(matrix, 29);
}