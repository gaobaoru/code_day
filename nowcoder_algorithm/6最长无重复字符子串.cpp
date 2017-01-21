
我的首页 > 代码本 > 最长无重复字符子串

对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。

给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，且长度小于等于500。
测试样例：

"aabcb",5

返回：3



public:
    int longestSubstring(string A, int n) {
        // write code here
        int pre  = 1;
        int i = 1;
        map<char, int> str_map;
        str_map[A[0]] = 0;
        vector<int> result;
        result.push_back(1);
        for(i = 1; i < n; i++){
            if(str_map.count(A[i]) == 0){
                ++pre;
                result.push_back(pre);
            }else{
                if(str_map[A[i]] < i - pre)
                    ++pre;
                if(str_map[A[i]] > i - pre)
                    pre = i - str_map[A[i]];
                result.push_back(pre);
            }
            str_map[A[i]] = i;
        }
        sort(result.begin(), result.end());
        return result.back();
    }
};
