题目描述

Given a string containing just the characters'('and')', find the length of the longest valid (well-formed) parentheses substring. 

For"(()", the longest valid parentheses substring is"()", which has length = 2. 

Another example is")()())", where the longest valid parentheses substring is"()()", which has length = 4. 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int last_right = -1;
        stack<int> lefts;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    last_right = i;
                }else{
                    lefts.pop();
                    if(lefts.empty()){
                        max_len = max(max_len,i-last_right);
                    }else{
                        max_len = max(max_len,i-lefts.top());
                    }
                }
            }
        }
        return max_len;
    }
};
