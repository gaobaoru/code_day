题目描述


Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.


For example, given candidate set2,3,6,7and target7,
A solution set is:
[7]
[2, 2, 3] 

class Solution {
public:
    //时间复杂度Ｏ(n!),空间复杂度Ｏ(n)
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> path;
        dfs(candidates, path, result, target, 0);
        return result;
    }
    
    void dfs(vector<int> &candidates, vector<int> &path,
            vector<vector<int> > &result, int gap, int start){
        if(gap == 0){
            result.push_back(path);
            return;
        }
        for(size_t i = start; i < candidates.size(); i++){
            if(gap < candidates[i]) return;
            path.push_back(candidates[i]);
            dfs(candidates, path, result, gap-candidates[i], i);
            path.pop_back();
        }
    }
};
