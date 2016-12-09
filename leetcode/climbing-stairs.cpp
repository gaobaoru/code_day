题目描述

You are climbing a stair case. It takes n steps to reach to the top. 

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int climbStairs(int n) {
        int pre = 0;
        int cur = 1;
        int tmp;
        for(int i = 1; i <= n; i++){
            tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur;
    }
};
