题目描述

Evaluate the value of an arithmetic expression in Reverse Polish Notation. 

Valid operators are+,-,*,/. Each operand may be an integer or another expression. 

Some examples: 
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

时间复杂度O（n）,空间复杂度O（logn）
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for(auto token : tokens){
            if(!is_operator(token)){
                s.push(token);
            }else{
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if(token[0] == '+') x+=y;
                else if(token[0] == '-') x-=y;
                else if(token[0] == '*') x*=y;
                else x/=y;
                s.push(to_string(x));
            }
        }
        return stoi(s.top());
    }
private:
    bool is_operator(string &op){
        return op.size()==1 && string("+-*/").find(op) != string::npos;
    }
};
