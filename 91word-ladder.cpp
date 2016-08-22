题目描述


Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]

As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(n)
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> current, next;
        unordered_set<string> visited;
        int level = -1;
        
        auto state_is_valid = [&](const string& s){
            return dict.find(s) != dict.end() || s == end;
        };
        
        auto state_is_target = [&](const string& s){
            return s == end;
        };
        
        auto state_extend = [&](const string &s){
            unordered_set<string> result;
            for(size_t i = 0; i < s.size(); i++){
                string new_word(s);
                for(char c = 'a'; c < 'z'; c++){
                    if(c == new_word[i]) continue;
                    swap(c, new_word[i]);
                    if(state_is_valid(new_word) &&
                      visited.find(new_word) == visited.end()){
                        result.insert(new_word);
                    }
                    swap(c, new_word[i]);
                }
            }
            return result;
        };
        
        current.push(start);
        visited.insert(start);
        while(!current.empty()){
            ++level;
            while(!current.empty()){
                const auto state = current.front();
                current.pop();
                
                if(state_is_target(state))
                    return level+1;
                
                const auto& new_states = state_extend(state);
                for(const auto& new_state : new_states){
                    next.push(new_state);
                    visited.insert(new_state);
                }
            }
            swap(next, current);
        }
        return 0;
    }
};
