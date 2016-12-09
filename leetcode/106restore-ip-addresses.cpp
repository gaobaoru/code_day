题目描述


Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given"25525511135",

return["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

class Solution {
public:
    //时间复杂度Ｏ(n^4),空间复杂度Ｏ(n)
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> ip;
        dfs(s, ip, result, 0);
        return result;
    }
    
    void dfs(string &s, vector<string> &ip,
            vector<string> &result, size_t start){
        if(ip.size() == 4 && start == s.size()){
            result.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
            return;
        }
        if(s.size() - start > (4 - ip.size())*3)
            return;
        if(s.size() - start < (4 - ip.size()))
            return;
        
        int num = 0;
        for(int i = start; i < start + 3; i++){
            num = num * 10 + (s[i] - '0');
            if(num < 0 || num > 255) continue;
            ip.push_back(s.substr(start, i-start+1));
            dfs(s, ip, result, i+1);
            ip.pop_back();
            
            if(num == 0) break;
        }
    }
};
