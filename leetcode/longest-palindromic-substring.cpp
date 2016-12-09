题目描述

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring. 

时间复杂度O（n^2）,空间复杂度O（n^2）
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);
        int max_len = 1, start = 0;
        for(int j = 0; j < n; j++){
            f[j][j] = true;
            for(int i = 0; i < j; i++){
                f[i][j] = (s[i]==s[j] &&(j-i<2 || f[i+1][j-1]));
                if(f[i][j] && max_len <(j-i+1)){
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start,max_len);
    }
};
