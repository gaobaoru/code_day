题目描述

Implement pow(x, n). 


class Solution {
public:
    //时间复杂度O(logn),空间复杂度O(1)
    double pow(double x, int n) {
        if(n < 0) return 1.0 / power(x, -n);
        else return power(x, n);
    }
    
    double power(double x, int n){
        if(n == 0) return 1;
        double v = power(x, n/2);
        if(n % 2 == 0) return v * v;
        else return v * v * x;
    }
};

