题目描述

Given two binary strings, return their sum (also a binary string). 

For example,
 a ="11"
 b ="1"
 Return"100". 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int n = a.size()>b.size() ? a.size() : b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        for(int i=0;i<n;i++){
            int ai = i < a.size() ? a[i] - '0' : 0;
            int bi = i < b.size() ? b[i] - '0' : 0;
            int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        if(carry == 1)
            result.insert(result.begin(),'1');
        return result;
    }
};
