/*
Question : Given number of pages in n different books and m students. 
           The books are arranged in ascending order of number of pages. 
           Every student is assigned to read some consecutive books. 
           The task is to assign books in such a way that the maximum number of pages assigned 
           to a student is minimum. 

For example : Input : pages[] = {12, 34, 67, 90} , m = 2
              Output : 113 
*/

//Similar question in leetcode : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/*
Approach:

Here we will be using binaryseach to solve this problem.
Binary Search can be used in 2 places
    1. When we need to search something in sorted array.
    2. When we need to allocate things in contagious manner.

Algo:
    Since we need to minimize the maximum number of pages a student reads.

    Here we will set:
        start=maxPages.
        end=Sum.

        now we will start the algo.

        // func for check
        bool check(pages, student, res){
            sum=0;
            stu=1;
            for(i: pages){
                if(pages[i]>res) return false;
                else{
                    if(sum+pages[i]>res){
                        student++;
                        sum=pages[i];
                    }
                    else{
                        sum=sum+pages[i];
                    }
                }
            }
            return stu <= student;
        }

        // func for binarySearch
        while(start<end){
            mid=start+(end-start)/2;
            bool check = (pages,students,mid);
            if(bool):
                store ans.
                check in left part.
            else:
                check in right part.
        }

For example:
    pages=[12,34,67,90];
    student=2;

    start=max(pages)=90
    end=sum(pages)=203

    while(start<end)
    loop-1 : start=90,end=203
        mid = 146
        func check:
                sum=0;student=1;
            12>146 -> F | sum = 12
            46>146 -> F | sum = 46
            113>146 -> F| sum = 113
            203>146 -> T| student=2;sum=90
        
        return true;
        ans = 146;

    loop-2 : start=90,end=145
    mid = 117
    func check:
            sum=0;student=1;
        12>117 -> F | sum = 12
        46>117 -> F | sum = 46
        113>117 -> F| sum = 113
        203>117 -> T| student=2;sum=90

        return true;
        ans = 117;

    loop-3 : start=90,end=116
    mid = 103
    func check:
            sum=0;student=1;
        12>103 -> F | sum = 12
        46>103 -> F | sum = 46
        113>103 -> T| student=2;sum=67
        203>103 -> T| student=3;sum=90

        return false;

    loop-4 : start=104,end=116
    mid = 110
    func check:
            sum=0;student=1;
        12>110 -> F | sum = 12
        46>110 -> F | sum = 46
        113>110 -> T| student=2;sum=67
        203>110 -> T| student=3;sum=90

        return false;

    loop-5 : start=111,end=116
    mid = 113
    func check:
            sum=0;student=1;
        12>113 -> F | sum = 12
        46>113 -> F | sum = 46
        113>113 -> F| sum = 113
        203>113 -> T| student=2;sum=90

        return true;
        ans = 113;

    loop-6 : start=111,end=112
    mid = 111
    func check:
            sum=0;student=1;
        12>111 -> F | sum = 12
        46>111 -> F | sum = 46
        113>111 -> t| student=2;sum=67 
        203>111 -> T| student=3;sum=90

        return false;

    loop-7 : start=112,end=112
    mid = 112
    func check:
            sum=0;student=1;
        12>112 -> F | sum = 12
        46>112 -> F | sum = 46
        113>112 -> t| student=2;sum=67 
        203>112 -> T| student=3;sum=90

        return false;

    loop-7 : start=113,end=112
    
    since : start>end
    while loop exits;


*/





#include <iostream>
using namespace std;

bool check(int arr[], int n, int len, int res){
    int student = 1;
    int sum=0;
    for(int i=0;i<len;i++){
        if(arr[i]>res){
            return false;
        }
        else{
            if(sum+arr[i]>res){
                student++;
                sum=arr[i];
            }
            else{
                sum=sum+arr[i];
            }
        }
    }
    return student <= n;
}

int minPages(int pages[], int student, int len){
    int maxPages=INT32_MIN;
    int sum=0;
    for(int i=0;i<len;i++){
        if(pages[i]>maxPages){
            maxPages=pages[i];
        }
        sum += pages[i];
    }

    int ans=0;

    while(maxPages<=sum){
        int mid = maxPages + (sum-maxPages)/2;
        bool c = check(pages, student, len, mid);
        if(c){
            ans=mid;
            sum=mid-1;
        }
        else{
            maxPages=mid+1;
        }
    }
    return ans;
}

int main(){

    int pages[] = {12, 34, 67, 90};
    int students = 2;

    int ans = minPages(pages,students,4);

    cout<<"ans : "<<ans<<endl;

    return 0;
}
