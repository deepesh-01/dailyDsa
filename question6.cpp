/*
Question : You are given an unsorted array with both positive and negative elements.
           You have to find the smallest positive number missing from the array in O(n) time 
           using constant extra space. You can modify the original array.

For example : 1-> arr[] = {10,8,5,2,1};
                  ans = 3;
                  As we can see 1 and 2 are present but after that
                  3 is the first missing positive integer.
                  
              2-> arr[] = {-1,3,5,2,1};
                  ans = 4;
                  As we can see 1,2 and 3 present but after that
                  3 is the first missing positive integer.
              
*/

/*

Approach : 

    Here since we need to find the first positive missing integer.
    We can see the either the missing interger will lie between 0<n (n is size or arrya)
    or it will be n+1.

    So if we place all the positive integer which are 
    greater than 0 and less than n i.e.(0<i<n) in their indexes 
    and then traverse the array the first value 
    which does not equal to its index will be our ans.

    If all the values get placed in their indexes our ans will be last postion + 1.

    In first example:
        -> our array is : {10,8,5,2,1}
        -> placing all values in correct places : {1,2,5,8,10}
        -> we can clearly see that 3 is not present in 3rd place so it is the ans.

*/


#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n);
 
int firstMissingPositive(int arr[], int n){

    //placing all values in their respective positions
    for(int i=0;i<n;i++){
        while(arr[i] >= 1 && arr[i]<=n && arr[i] != arr[arr[i]-1]){
            swap(arr[i],arr[arr[i]-1]);
            print(arr,n);
        }
    }

    //checking for the ans;
    for(int i=0;i<n;i++){
        if(arr[i] != i+1){
            return i+1;
        }
    }

    return n+1;
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
int main()
{
    int arr[] = {-1,3,5,2,1};
    int n = 5;
    
    print(arr,n);
 
    int ans = firstMissingPositive(arr, n);
 
    cout << ans;
 
    return 0;
}