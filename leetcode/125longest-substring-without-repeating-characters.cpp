题目描述


Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1. 


class Solution {
public:
    //时间复杂度为Ｏ(n),空间复杂度Ｏ(1)
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int start = 0;
        fill(last, last+ASCII_MAX, -1);
        int max_len = 0;
        for(int i = 0; i < s.size(); i++){
            if(last[s[i]] >= start){
                max_len = max(max_len, i - start);
            	start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size()-start, max_len);
    }
};
