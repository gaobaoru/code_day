题目描述

Given an array of strings, return all groups of strings that are anagrams. 

Note: All inputs will be in lower-case. 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > group;
        for(const auto &s : strs){
            auto key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        vector<string> result;
        for(auto it = group.cbegin(); it != group.cend(); it++){
            if(it->second.size() > 1)
                result.insert(result.end(), it->second.begin(), it->second.end());
        }
        return result;
    }
};
