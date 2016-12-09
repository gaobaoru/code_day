题目描述


Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23" Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 

class Solution {
public:
    //时间复杂度O(3^n),空间复杂度O(n)
    const vector<string> keyboard {" ", "", "abc", "def",
                                  "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string& digits) {
        vector<string> result;
        //if(digits.empty()) return result;
        dfs(digits, 0, "", result);
        return result;
    }
    
    void dfs(string& digits, size_t cur, string path, vector<string>& result){
        if(cur == digits.size()){
            result.push_back(path);
            return;
        }
        for(auto c : keyboard[digits[cur] - '0']){
            dfs(digits, cur+1, path+c, result);
        }
    }
};
