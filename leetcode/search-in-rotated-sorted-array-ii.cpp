题目描述

Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed? 

Would this affect the run-time complexity? How and why? 

Write a function to determine if a given target is in the array. 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    bool search(int A[], int n, int target) {
        int first = 0, last = n;
        while(first != last){
            const int mid = (first + last) / 2;
            if(A[mid] == target) return true;
            if(A[first] < A[mid]){
                if(A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            }else if(A[first] > A[mid]){
                if(A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }else{
                first++;
            }
        }
        return false;
    }
};
