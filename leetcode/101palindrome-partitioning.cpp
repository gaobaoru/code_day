题目描述


Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s ="aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]


class Solution {
public:
    //时间复杂度Ｏ(2^n),空间复杂度Ｏ(n)
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        dfs(s, path, result, 0, 1);
        return result;
    }
    
    void dfs(string& s, vector<string>& path, 
             vector<vector<string> >& result, 
             size_t prev, size_t start){
        if(start == s.size()){
            if(isPalindrome(s, prev, start-1)){
                path.push_back(s.substr(prev, start-prev));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        if(isPalindrome(s, prev, start-1)){
            path.push_back(s.substr(prev, start-prev));
            dfs(s, path, result, start, start+1);
            path.pop_back();
        }
        dfs(s, path, result, prev, start+1);
    }
    
    bool isPalindrome(string& s, int start, int end){
        while(start < end && s[start] == s[end]){
            start++;
            end--;
        }
        return start>=end;
    }
};
