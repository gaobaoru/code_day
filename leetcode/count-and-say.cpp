题目描述

The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ... 

1is read off as"one 1"or11.
 11is read off as"two 1s"or21.
 21is read off as"one 2, thenone 1"or1211. 

Given an integer n, generate the nth sequence. 

Note: The sequence of integers will be represented as a string. 

时间复杂度O（n^2）,空间复杂度O（n）
class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while(--n){
            s = getNext(s);
        }
        return s;
    }
    string getNext(const string& s){
        stringstream ss;
        for(auto i = s.begin(); i != s.end();){
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss<<distance(i,j)<<*i;
            i = j;
        }
        return ss.str();
    }
};
