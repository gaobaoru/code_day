题目描述


Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

For example,
S ="ADOBECODEBANC"
T ="ABC"

Minimum window is"BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string"".

If there are multiple such windows, you are guaranteed 
that there will always be only one unique minimum window in S. 

class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(1)
    string minWindow(string S, string T) {
        if(S.empty()) return "";
        if(S.size() < T.size()) return "";
        
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count, appeared_count+ASCII_MAX, 0);
        fill(expected_count, expected_count+ASCII_MAX, 0);
        
        for(size_t i = 0; i < T.size(); i++) expected_count[T[i]]++;
        int minWin = INT_MAX, min_start = 0;
        int index = 0, wnd_start = 0;
        for(size_t wnd_end = 0; wnd_end < S.size(); wnd_end++){
            if(expected_count[S[wnd_end]] > 0){
                appeared_count[S[wnd_end]]++;
                if(appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])
                    index++;
            }
            if(index == T.size()){
                while(appeared_count[S[wnd_start]] > expected_count[S[wnd_start]]
                     || expected_count[S[wnd_start]] == 0){
                    appeared_count[S[wnd_start]]--;
                    wnd_start++;
                }
                if(minWin > (wnd_end - wnd_start + 1)){
                    minWin = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }
        if(minWin == INT_MAX) return "";
        else return S.substr(min_start, minWin);
    }
};
