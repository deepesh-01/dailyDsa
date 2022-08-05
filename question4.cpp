/*
Question : Given a non-negative integer x, compute and return the square root of x.

            Since the return type is an integer, the decimal digits are truncated, 
            and only the integer part of the result is returned.

    Note: You are not allowed to use any built-in exponent function or operator, 
        such as pow(x, 0.5) or x ** 0.5.

For example :  
        Input: x = 4
        Output: 2

        Input: x = 8
        Output: 2
        Explanation: The square root of 8 is 2.82842..., and since the decimal 
                     part is truncated, 2 is returned.
*/

/*

Approach : 
We will be using binary search to solve this problem.

We know that square root of a number is : number>=root>=0.

Thus we can se that we have a range from 0->number where our answer lies.

0 -> while(s<=e)    //here s=0 and e=n
    1 ->  Take out square of mid value.
    2 ->  If(square(mid) <= number)
        2.2-> store ans;
        2.3-> start = mid+1;
    3 ->  else
        3.1 end = mid-1;
return ans;

For example for num=10;

Start   |   End |   Mid |               |  ans
-----------------------------------------------
  0     |   10  |    5  |     25>10     |   -
  1     |   4   |    2  |     4<10      |   2
  3     |   4   |    3  |     9<10      |   3
  4     |   4   |    4  |     16>10     |   3

  return 3; 

*/

#include <iostream>
using namespace std;

int sqrt(int n){
    int start = 0, end = 10;
    int ans;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(mid <= n/mid){
            ans = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    return ans;
}

int main(){
    int n=39;
    int ans = sqrt(n);
    cout<<"Sqrt of "<<n<<" is : "<<ans<<endl;
}