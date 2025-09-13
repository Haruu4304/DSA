/*
Problem Statement : 
Find the next element
def - here they have given us one array of alphabets and given the key -> (alphabet)
now you have to find the next element of that alphabet
like -> a , b , c , d and key = c 
return d.
*/

#include<bits/stdc++.h>
using namespace std;

char findNextElem(vector<char> arr , char key){
    //basic initialization
    int start = 0;
    int end = arr.size()-1;
    char res = '#';
    while(start <= end){
        //calculate mid - 
        int mid = start + (end - start)/2;
        //basic check
        if(arr[mid] == key){
            start = mid+1;
        }else if(arr[mid] < key){ //key is greater
            start = mid+1;
        }else if(arr[mid] > key){//key is smaller
            res = arr[mid];   // possible answer
            end = mid-1;
        }
    }
    return res;
}

int main(){
    vector<char> arr = {'a', 'c' , 'f' , 'h'};
    char key = 'f';

    cout << findNextElem(arr ,key);
}