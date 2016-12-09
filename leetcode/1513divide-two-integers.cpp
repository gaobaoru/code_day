题目描述


Divide two integers without using multiplication, division and mod operator. 

class Solution {
public:
    //时间复杂度Ｏ(logn),空间复杂度Ｏ(1)
    int divide(int dividend, int divisor) {
        long long a = dividend > 0 ? dividend : -(long long)dividend;
        long long b = divisor > 0 ? divisor : -(long long)divisor;
        long long result = 0;
        while(a >= b){
            long long c = b;
            for(int i = 0; a >= c; ++i, c <<= 1){
                a -= c;
                result += 1 << i;
            }
        }
        return ((dividend^divisor) >> 31) ? (-result) : result;
    }
};
