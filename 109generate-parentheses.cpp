题目描述


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        if(n > 0) generate(n, path, result, 0, 0);
        return result;
    }
    
    void generate(int n, string &path, vector<string> &result,
                 int left, int right){
        if(left == n){
            string s(path);
            result.push_back(s.append(n-right, ')'));
            return;
        }
        path.push_back('(');
        generate(n, path, result, left+1, right);
        path.pop_back();
        
        if(left > right){
            path.push_back(')');
            generate(n, path, result, left, right+1);
            path.pop_back();
        }
    }
};
