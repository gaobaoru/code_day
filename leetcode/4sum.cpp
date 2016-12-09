题目描述

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target. 

Note: 
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d) 
The solution set must not contain duplicate quadruplets. 

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

  A solution set is:
  (-1,  0, 0, 1)
  (-2, -1, 1, 2)
  (-2,  0, 0, 2)

时间复杂度O（n^2）,空间复杂度O（n^2）
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size() < 4) return result;
        sort(num.begin(),num.end());
        
        unordered_multimap<int, pair<int, int> > multimap;
        for(int i=0; i+1<num.size(); i++){
            for(int j=i+1; j<num.size(); j++)
                multimap.insert(make_pair(num[i]+num[j], make_pair(i,j)));
        }
        
        for(auto i=multimap.begin(); i!=multimap.end(); i++){
            int x = target - i->first;
            auto range = multimap.equal_range(x);
            for(auto j = range.first; j!=range.second; j++){
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if(a!=c && a!=d && b!=c && b!=d){
                    vector<int> vec = {num[a], num[b], num[c], num[d]};
                    sort(vec.begin(),vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

