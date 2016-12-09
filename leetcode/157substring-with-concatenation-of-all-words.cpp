题目描述


You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
and without any intervening characters.

For example, given:
S:"barfoothefoobarman"
L:["foo", "bar"]

You should return the indices:[0,9].
(order does not matter). 


class Solution {
public:
    //时间复杂度为Ｏ(n*m),空间复杂度Ｏ(m)
    vector<int> findSubstring(string S, vector<string> &L) {
        size_t wordLength = L.front().size();
        size_t dictLength = wordLength * L.size();
        vector<int> result;
        
        if(S.length() < dictLength) return result;
        
        unordered_map<string, int> wordCount;
        for(auto const& word : L) ++wordCount[word];
        
        for(auto i = begin(S); i <= prev(end(S), dictLength); i++){
            unordered_map<string, int> unused(wordCount);
            for(auto j = i; j != next(i, dictLength); j+= wordLength){
                auto pos = unused.find(string(j, next(j, wordLength)));
                if(pos == unused.end() || pos->second == 0) break;
                if(--pos->second == 0) unused.erase(pos);
            }
            if(unused.size() == 0) result.push_back(distance(begin(S), i));
        }
        return result;
    }
};
