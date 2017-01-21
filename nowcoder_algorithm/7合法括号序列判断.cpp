

对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
测试样例：

"(()())",6

返回：true

测试样例：

"()a()()",7

返回：false

测试样例：

"()(()()",7

返回：false


class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int count = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == '(')
                count++;
            else if(A[i] == ')')
                count++;
            else
                return false;
             
            if(count < 0)
                return false;
        }
        return true;
    }
};
