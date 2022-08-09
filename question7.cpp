/*
Question -> Given two positive integers N and k, write a program 
            to print the kth largest factor of N.

            A positive integer d is said to be a factor of another positive integer N 
            if when N is divided by d, the remainder obtained is zero. 


For example ->  For number 12, there are 6 factors 1, 2, 3, 4, 6, 12. 
                Every positive integer k has at least two factors, 1 and the number k itself.

Input -> n=9,k=2
Output -> 3
Explanation -> Factors of 9 are -> 1,3,9. Therefore, 2nd largest factor ok 9 is 3;

*/

// leetcode similar question -> https://leetcode.com/problems/the-kth-factor-of-n/

/*
Approach :
    Since we know that if n%i==0, i is said to be the factor of n;
    -> for(i=0; i<n; i++)
    ->     if(n%i==0) store i;
    -> return arr[k-1];

    In this approach our time complexity will be O(n).

    We can solve this by another approach.
    For all factors of n, 
    We know that first half factors are less than square root of n.
    Thus, we can get the other half factor by dividing n by its first half factors.

        ** We will run the loop till (n/i)+1 to take care of edge cases. **
        ** Do a dry run for 12 and you will get this.                    **

    ->  vector<int> ans; int i=2;
    ->  ans.push(i)
    ->  while(i < (n/i)+1){ 
        ->    if(n%i==0) ans.push(i);
        }

    ->  if(i==n/i) i--;

    ->  while(i>1){
        ->    if(n%i==0){
            ->    if(n/i == ans.back()) {i--; continue;} 
            ->    else factors.push_back(n/i); 
            }
    }

    -> ans.push(n)

    -> return ans[k-1];

*/


#include <iostream>
using namespace std;
#include <vector>

void print(vector<int> v);

int kLargestFactor(int n,int k){
    vector<int> factors;
    factors.push_back(1);
    int i=2;
    while(i<(n/i)+1){
        if(n%i==0)factors.push_back(i);
        i++;
    }

    print(factors);    
    if(i*i==n) i--;

    while(i>1){
        cout<<i<<endl;
        if(n%i==0)
            if(n/i == factors.back()) {i--; continue;} 
            else factors.push_back(n/i);
        i--;
    }

    factors.push_back(n);

    print(factors);
    if(k<=factors.size()) return factors[k-1];
    return -1;

}

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "; 
    }
    cout<<endl;
}

int main(){
    int n=9;
    int k=2;

    cout<<k<<" largest factor of "<<n<<" is : "<<kLargestFactor(n,k)<<endl;
    return 0;
}