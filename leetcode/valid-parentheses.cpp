题目描述

Given a string containing just the characters'(',')','{','}','['and']', determine if the input string is valid. 

The brackets must close in the correct order,"()"and"()[]{}"are all valid but"(]"and"([)]"are not. 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for(auto c : s){
            if(left.find(c) != string::npos){
                stk.push(c);
            }else{
                if(stk.empty() || stk.top() != left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
