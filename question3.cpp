/*
Question : Given an array of integers, return a new array such that each element at 
           index i of the new array is the product of all the numbers in the original
           array except the one at i.

           Try to look for a solution where we don't use division.

For example :  
        If our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
        If our input was [3, 2, 1], the expected output would be [2, 3, 6]
*/

/*
Approach 1:
    We will create a prefix product and postfix product for the array;

    Prefix product is -> product of all the elements before the current element.
    Postfix product is -> product of all the elements after the current element.

    For example in {1,2,3,4,5} 
                prefix of 3 is -> 2*1 = 2;
      like wise postfix of 3 is -> 4*5 = 20; 

    Therefore : 
    arr = [1,2,3,4,5]
    prefix = [1,1,2,6,24] (prefix for 0th element will always be 1)
    postfix = [120,60,20,5,1] (postfix for nth elements will always be 1)

    // now product for ith element will be -> prefix[i]*postfix[i];
    
    product = [120,60,40,30,24]

    Time Complexity -> O(n)
    Space Complexity -> O(n)

Approach 2: 
    We will look for a solution where we don't need prefix and postfix arrays;
    We will be working directly on product array.

    1. We will store the prefix values in product array.
    2. We will traverse array from(i : n-1 -> 0)
        2.1  Then we will compute the postfix value for the nth element.
        2.2  And then multiply it with prefix value.

    arr = [1,2,3,4,5]
    product = [1,1,2,6,24] (in first pass)
    product = [120,60,40,30,24] (in second pass)

*/

#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* getProduct(int arr[], int size){
    int *prod = new int[size];
    prod[0]=1;

    for(int i=1;i<size;i++){
        prod[i] = arr[i-1] * prod[i-1];
    }

    int postFix = 1;
    for(int i=size-1;i>0;i--){
        prod[i] = prod[i]*postFix;
        postFix = postFix*arr[i];
    }
    prod[0] = postFix;

    return prod;
}


int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    /* Sample testcases

    int arr[3] = {3,2,1};
    int size = 3;
    output = {2,3,6};

    int arr[5] = {1,2,3,4,0};
    int size = 5;
    output = {0,0,0,0,24}
    
    */

    cout<<"Input array is : ";
    printArray(arr,size);

    int *prod = getProduct(arr,size);

    cout<<"Product array is : ";
    printArray(prod,size);
    
    return 0;
}
