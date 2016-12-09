题目描述


Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s ="aab",
Return1since the palindrome partitioning["aa","b"]could be produced using 1 cut. 

class Solution {
public:
    //时间复杂度Ｏ(n^2),空间复杂度Ｏ(n^2)
    int minCut(string s) {
        const int n = s.size();
        int f[n+1];
        for(int i = 0; i <=n; i++)
            f[i] = n - i - 1;
        bool p[n][n];
        fill_n(&p[0][0], n*n, false);
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i < 2 || p[i+1][j-1])){
                    p[i][j] = true;
                    f[i] = min(f[i], f[j+1]+1);
                }
            }
        }
        return f[0];
    }
};
