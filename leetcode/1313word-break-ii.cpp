题目描述


Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].

A solution is["cats and dog", "cat sand dog"]. 

class Solution {
public:
    //时间复杂度Ｏ(n^2),空间复杂度Ｏ(n^2)
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.length()+1, false);
        vector<vector<bool> > prev(s.length()+1, vector<bool>(s.length()));
        f[0] = true;
        for(size_t i = 1; i <= s.length(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(f[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    f[i] = true;
                    prev[i][j] = true;
                }
            }
        }
        vector<string> result;
        vector<string> path;
        gen_path(s, prev, s.length(), path, result);
        return result;
    }
private:
    void gen_path(const string &s, const vector<vector<bool> > &prev,
                 int cur, vector<string> &path,
                 vector<string> &result){
        if(cur == 0){
            string tmp;
            for(auto iter = path.crbegin(); iter != path.crend(); ++iter){
                tmp += *iter + " ";
            }
            tmp.erase(tmp.end()-1);
            result.push_back(tmp);
        }
        
        for(size_t i = 0; i < s.length(); ++i){
            if(prev[cur][i]){
                path.push_back(s.substr(i, cur-i));
                gen_path(s, prev, i, path, result);
                path.pop_back();
            }
        }
    }
};
