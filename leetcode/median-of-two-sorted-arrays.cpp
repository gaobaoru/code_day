题目描述

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)). 

时间复杂度O（log(m+n)）,空间复杂度O（log(m+n)）
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total % 2 == 1)
            return find_kth(A, m, B, n, total/2+1);
        else
            return (find_kth(A, m, B, n, total/2)+find_kth(A, m, B, n, total/2+1)) / 2.0;
    }
private:
    static int find_kth(int A[], int m, int B[], int n, int k){
        if(m > n) return find_kth(B, n, A, m, k);
        if(m == 0) return B[k-1];
        if(k == 1) return A[0]<B[0]?A[0]:B[0];
        
        //divide k into two parts
        int A_index = (k/2)<m?(k/2):m;
        int B_index = k - A_index;
        if(A[A_index-1] < B[B_index-1])
            return find_kth(A+A_index, m-A_index, B, n, k-A_index);
        else if(A[A_index-1] > B[B_index-1])
            return find_kth(A, m, B+B_index, n-B_index, k-B_index);
        else
            return A[A_index-1];
    }
};
