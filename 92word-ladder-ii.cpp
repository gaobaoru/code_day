题目描述


Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]


Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.


class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(n)
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> current, next;
        unordered_set<string> visited;
        unordered_map<string, vector<string> > father;
        
        int level = -1;
        auto state_is_valid = [&](const string& s){
            return dict.find(s) != dict.end() || s == end;
        };
        auto state_is_target= [&](const string& s){
            return s == end;
        };
        auto state_extend = [&](const string &s){
            unordered_set<string> result;
            for(size_t i = 0; i < s.size(); i++){
                string new_word(s);
                for(char c = 'a'; c <= 'z'; c++){
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
        vector<vector<string> > result;
        current.insert(start);
        while(!current.empty()){
            ++level;
            if(!result.empty() && level+1 > result[0].size()) break;
            for(const auto& state : current)
                visited.insert(state);
            for(const auto& state : current){
                if(state_is_target(state)){
                    vector<string> path;
                    gen_path(father, path, start, state, result);
                    continue;
                }
                
                const auto new_states = state_extend(state);
                for(const auto& new_state : new_states){
                    next.insert(new_state);
                    father[new_state].push_back(state);
                }
            }
            current.clear();
            swap(current, next);
        }
        return result;
    }
private:
    void gen_path(unordered_map<string, vector<string> > &father,
                 vector<string> &path, const string &start, 
                 const string &word, vector<vector<string> > &result){
        path.push_back(word);
        if(word == start){
            if(!result.empty()){
                if(path.size() < result[0].size()){
                    result.clear();
                    result.push_back(path);
                }else if(path.size() == result[0].size()){
                    result.push_back(path);
                }else{
                    
                }
            }else{
                result.push_back(path);
            }
            reverse(result.back().begin(), result.back().end());
        }else{
            for(const auto& f : father[word]){
                gen_path(father, path, start, f, result);
            }
        }
        path.pop_back();
    }
};
