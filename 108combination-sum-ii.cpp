题目描述

Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.


For example, given candidate set10,1,2,7,6,1,5and target8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 

class Solution {
public:
    //时间复杂度Ｏ(n!),空间复杂度Ｏ(n)
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        dfs(num, path, result, target, 0);
        return result;
    }
    
    void dfs(vector<int> &num, vector<int> &path,
            vector<vector<int> > &result, int gap, int start){
        if(gap == 0){
            result.push_back(path);
            return;
        }
        int pre = -1;
        for(size_t i = start; i < num.size(); i++){
            if(num[i] == pre) continue;
            if(gap < num[i]) return;
            pre = num[i];
            path.push_back(num[i]);
            dfs(num, path, result, gap-num[i], i+1);
            path.pop_back();
        }
    }
};
