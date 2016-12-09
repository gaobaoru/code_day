题目描述

Given a number represented as an array of digits, plus one to the number. 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
    void add(vector<int> &digits, int digit){
        int c = digit;
        
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        
        if(c > 0) digits.insert(digits.begin(), 1);
    }
};
