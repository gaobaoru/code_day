题目描述


Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return[-1, -1].

For example,
Given[5, 7, 7, 8, 8, 10]and target value 8,
return[3, 4].

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound(A, 0, n-1, target);
        int upper = lower;
        while(upper < n){
            if(A[++upper] != target)
                break;
        }
        upper--;
        if(A[lower] != target)
            return vector<int> {-1, -1};
        else
            return vector<int> {lower,upper};
    }
    
    int lower_bound(int A[], int first, int last, int target){
        while(first != last){
            int mid = (first + last) / 2;
            if(target > A[mid]) first = ++mid;
            else last = mid;
        }
        return first;
    }
    
};
