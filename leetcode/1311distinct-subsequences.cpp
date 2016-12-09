题目描述


Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).

Here is an example:
S ="rabbbit", T ="rabbit"

Return3. 

class Solution {
public:
    //时间复杂度Ｏ(m*n),空间复杂度Ｏ(n)
    int numDistinct(string S, string T) {
        vector<int> f(T.size()+1);
        f[0] = 1;
        for(int i = 0; i < S.size(); i++){
            for(int j = T.size()-1; j >= 0; j--){
                f[j+1] += S[i]==T[j] ? f[j] : 0;
            }
        }
        return f[T.size()];
    }
};
