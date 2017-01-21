给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。

#include <iostream>
#include <string>
using namespace std;
 
int dp[1002][1002];
 
int max(const int &a, const int &b){
    return a >= b ? a : b;
}
 
int huiwen(string &s, const int &begin, const int &end){
    if(begin > end) return 0;
    if(begin == end){
        dp[begin][end] = 1;
        return 1;
    }
    if(dp[begin][end] != 0) return dp[begin][end];
    if(s[begin] == s[end]) dp[begin][end] = huiwen(s, begin+1, end-1) + 2;
    else dp[begin][end] = max(huiwen(s, begin+1, end), huiwen(s, begin, end-1));
    return dp[begin][end];
}
 
int main(){
    string s;
    while(cin >> s){
        int len = s.size();
        for(int i = 0; i <= len; i++){
            for(int j = 0; j <= len; j++){
                dp[i][j] = 0;
            }
        }
        int ans = huiwen(s, 0 , len-1);
        cout << len-ans << endl;
    }
    return 0;
}
