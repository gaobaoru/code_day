
题目描述

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? 
You would then have to re-design the function (ie, add an extra parameter).

class Solution {
public:
    //时间复杂度Ｏ(logn),空间复杂度Ｏ(1)
    int reverse(int x) {
        long long r = 0;
        long long t = x;
        t = t > 0 ? t : (-t);
        for(;t;t /= 10)
            r = r * 10 + t % 10;
        bool neg_sign  = x > 0 ? false : true;
        if(r > 2147483647 || (neg_sign && r > 2147483648))
            return 0;
        else{
            if(neg_sign)
                return -r;
            else
                return r;
        }
    }
};

