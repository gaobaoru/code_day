题目描述

Given a string s consists of upper/lower-case alphabets and empty space characters' ', return the length of last word in the string. 

If the last word does not exist, return 0. 

Note: A word is defined as a character sequence consists of non-space characters only. 

For example, 
 Given s ="Hello World",
 return5. 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while(*s){
            if(*s++ != ' ')
                ++len;
            else if(*s && *s != ' ')
                len = 0;
        }
        return len;
    }
};
