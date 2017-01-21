题目描述

Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice? 

For example,
 Given sorted array A =[1,1,1,2,2,3], 
Your function should return length =5, and A is now[1,1,2,2,3]. 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;
        int index = 2;
        for(int i=2;i<n;i++){
            if(A[i] != A[index-2])
                A[index++] = A[i];
        }
        return index;
    }
};
