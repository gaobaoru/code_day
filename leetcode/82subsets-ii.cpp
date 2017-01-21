题目描述


Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.


For example,
If S =[1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


class Solution {
public:
    //时间复杂度O(n^2),空间复杂度O(1)
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, S.begin(), result);
        return result;
    }
private:
    void subsets(vector<int>& S, vector<int>& path, 
                        vector<int>::iterator start, 
                        vector<vector<int> >& result){
        result.push_back(path);
        
        for(auto i = start; i < S.end(); i++){
            if(i != start && *i == *(i-1)) continue;
            path.push_back(*i);
            subsets(S, path, i+1, result);
            path.pop_back();
        }
    }
};
