题目描述

Given an array of integers, every element appears three times except for one. Find that single one. 

Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int singleNumber(int A[], int n) {
        const int bitNum = sizeof(int)*8;
        int count[bitNum];
        fill_n(&count[0], bitNum, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < bitNum; j++){
                count[j] += (A[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        
        int result = 0;
        for(int j = 0; j < bitNum; j++){
            result += (count[j] << j);
        }
        return result;
    }
};
