/*
Problem statement - 
Palindrome Partitioning : (memo approach)
here in input we have given one string and we have to break down(partition) so each partition 
elements should be palindrome - 
and return minimum number of partitions
Remember this -> 1) if it is already palindrome then no need for partition directly return 0.
*/
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isPalindrome(string s , int i , int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string &s , int i , int j){
    //base condition - 
    if(i >= j){
        return 0;
    }

    //if it is already palindrome then return 0 - 
    if(isPalindrome(s , i , j) == true){
        return 0;
    }

    //if already calculated then - 
    if(t[i][j] != -1){
        return t[i][j];
    }

    //else
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempAns = 1 + solve(s , i , k) + solve(s , k+1 , j);
        mn = min(tempAns , mn);
    }
    return t[i][j] = mn;
}

int palindrome_partition_memo(string s){
    memset(t , -1 , sizeof(t)); //fill the whole matrix with (-1)
    int i = 0;
    int j = s.length()-1;
    int result = solve(s , i , j);
    return result;
}

int main(){
    string s = "geek";

    cout << palindrome_partition_memo(s);
}