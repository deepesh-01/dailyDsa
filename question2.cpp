/* 
Question :
Sort 0s, 1s and 2s in a given array; 

For example:
input => int arr[] = {1,2,0,0,2,1,2,0,1,0,2};
output => int arr[] = {0,0,0,0,1,1,1,2,2,2,2};

*/

// Similar question in leetcode -> https://leetcode.com/problems/sort-colors/

/*

Approach : 
We will be using 3 pointers(low,mid & high) to traverse the array and get solution in one pass.

In the output array we see 
    0s are from 0 <-. low-1
    2s are from high+1 <-> n-1 (n is size of array)
    1s are from low <-> high-1 

1 -> initialise low=0, mid=0, high=n-1
2 -> while(mid<=high)
    2.1 ->  if(arr[i]==0) swap(arr[low],arr[mid) & low++, mid++;
    2.2 -> if(arr[i]==1) mid++;
    2.3 -> if(arr[i]==2) swap(arr[high],arr[mid]) & high--;

Time complexity = O(n) [One pass solution]
Space complexit = O(1)

*/

#include <iostream>
using namespace std;

int* sort(int arr[], int n){

    int low=0,mid=0,high = n-1;

    while(mid<=high){

        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++,mid++;
        }

        if(arr[mid]==1){
            mid++;
        }

        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    return arr;
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10] = {1,2,0,0,2,1,1,0,0,2};
    int n = 10;

    cout<<"The input array is : ";
    printArray(arr,n);

    int* result = sort(arr, n);


    cout<<"The output array is : ";
    printArray(result,n);

    /* Sample Test cases

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Input :  {0, 1, 2, 0, 1, 2}
    Output : {0, 0, 1, 1, 2, 2}

    Input :  {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
    Output : {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

    */

    return 0;
}
