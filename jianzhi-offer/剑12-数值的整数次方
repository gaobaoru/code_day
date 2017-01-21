题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 

class Solution {
public:
    double Power(double base, int exponent) {
        if(equal(base, 0.0) && exponent < 0) return 0.0;
        double result = 1.0;
        unsigned int abs_exponent = (unsigned int)exponent;
        
        if(exponent < 0) abs_exponent = (unsigned int)(-exponent);
        
        for(int i=0;i<abs_exponent;++i){
            result *= base;
        }
        
        if(exponent < 0)
            return 1.0 / result;
        else
            return result;
    }
    
    bool equal(double num1, double num2){
        if(num1 - num2 < 0.0000001 && num1 - num2 > -0.0000001)
            return true;
        else
            return false;
    }
};
