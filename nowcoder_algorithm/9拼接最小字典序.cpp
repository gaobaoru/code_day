

对于一个给定的字符串数组，请找到一种拼接顺序，使所有小字符串拼接成的大字符串是所有可能的拼接中字典序最小的。

给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。
测试样例：

["abc","de"],2

"abcde"

class Prior {
public:
    string findSmallest(vector<string> strs, int n) {
        // write code here
        string result;
        std::sort(strs.begin(), strs.end(), compare);
        for(int i = 0; i < n; i++)
            result += strs[i];
        return result;
    }
private:
    static bool compare(string a, string b){
        return a+b<b+a;
    }
};
