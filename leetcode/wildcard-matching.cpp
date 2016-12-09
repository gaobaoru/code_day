题目描述

Implement wildcard pattern matching with support for'?'and'*'. 
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

时间复杂度O（n*m）,空间复杂度O（1）
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        for(str = s, ptr = p; *str != '\0'; str++, ptr++){
            switch(*ptr){
                case '?':
                	break;
                case '*':
                	star = true;
                	s = str, p = ptr;
                	while(*p == '*') p++;
                	str = s - 1;
                	ptr = p - 1;
                	break;
                default:
                	if(*str != *ptr){
                        if(!star) return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
            }
        }
        while(*ptr == '*') ptr++;
        return (*ptr == '\0');
    }
};
