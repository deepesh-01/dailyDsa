/* 
Question :
Given a list of numbers and a number k, return(true/false) whether any two numbers from the list add up to k.

For example:
Given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

*/

// Similar question in leetcode -> https://leetcode.com/problems/two-sum/

/*

Approach : 
We will be using hashing to solve the problem

1 -> We create an empty unordered set.
2 ->  Loop from 0->n
    2.1 -> val = sum - arr[i]
    2.2 -> if(set.find(val) == true) return true;
    2.3 else set.insert(val)

Time complexity = O(n)
Space complexit = O(n)

*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool check(int *arr, int size, int k){
    unordered_set<int> s;
    for(int i=0;i<size;i++){
        int val = k-arr[i];
        if(s.find(val) != s.end()){
            return true;
        }
       s.insert(arr[i]);
    }
    return false;
}

int main(){
    int arr[4] = {10,15,3,7};
    int size = 4;
    int k=12;

    /* Sample Test cases

    int arr[5] = {0, -1, 2, -3, 1};
    int size=5;
    int k=-2;
    Ans -> true

    int arr[5] = {1, -2, 1, 0, 5};
    int size=5;
    int k=0;
    Ans -> false

    */


    bool answer = check(arr,size,k);

    cout<<"Pair found : "<<answer<<endl;
    return 0;
}