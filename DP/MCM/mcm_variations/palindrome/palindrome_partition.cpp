/*
Problem statement - 
Palindrome Partitioning : 
here in input we have given one string and we have to break down(partition) so each partition 
elements should be palindrome - 
and return minimum number of partitions
Remember this -> 1) if it is already palindrome then no need for partition directly return 0.
*/

#include<bits/stdc++.h>
using namespace std;

//partitiong check
bool isPalindrome(string s , int i , int j){
    while(i < j){//check until the string is get empty
        if(s[i] != s[j]){ //1st element and the last check karo agar same nahi hai toh
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string &s, int i , int j){
    //step 1 : base condition
    if(i >= j){ //if the string is empty or it contains only 1 element then no need to partition
        return 0;
    }

    //if the given string is palindrome itself so return 0
    if(isPalindrome(s , i , j) == true){
        return 0;
    }

    // k loop - 
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempAns = 1 +  solve(s , i , k) + solve(s , k+1 , j);
        mn = min(tempAns , mn);
    }
    return mn;
}

int palindrome_partition(string s){
    int i=0;
    int j = s.length() - 1;
    int result = solve(s , i , j); //recursive call
    return result;
}


int main(){
    string s = "";
    cout << palindrome_partition(s);
}