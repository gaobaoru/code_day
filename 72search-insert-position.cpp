题目描述


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 

class Solution {
public:
    //时间复杂度为O(logn),空间复杂度为O(1)
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A, 0, n-1, target);
    }
    
    int lower_bound(int A[], int first, int last, int target){
        while(first <= last){
            int mid = (first + last) / 2;
            if(target == A[mid]) return mid;
            if(target > A[mid]) first = mid + 1;
            else last = mid - 1;
        }
        return first;
    }
};
