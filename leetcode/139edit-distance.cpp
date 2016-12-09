题目描述


Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character 

class Solution {
public:
    //时间复杂度Ｏ(m*n),空间复杂度Ｏ(m*n)
    int minDistance(string word1, string word2) {
        const size_t n = word1.size();
        const size_t m = word2.size();
        int f[n+1][m+1];
        for(int i = 0; i <= n; i++)
            f[i][0] = i;
        for(int j = 0; j <= m; j++)
            f[0][j] = j;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1];
                }else{
                    f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
                }
            }
        }
        return f[n][m];
    }
};

