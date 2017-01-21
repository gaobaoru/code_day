

编写一个类,只能用两个栈结构实现队列,支持队列的基本操作(push，pop)。

给定一个操作序列ope及它的长度n，其中元素为正数代表push操作，为0代表pop操作，保证操作序列合法且一定含pop操作，请返回pop的结果序列。
测试样例：

[1,2,3,0,4,0],6

返回：[1,2]



public:
    vector<int> twoStack(vector<int> ope, int n) {
        // write code here
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(ope[i] != 0)
                push(ope[i]);
            else
                result.push_back(pop());
        }
        return result;
    }
private:
    stack<int> s1;
    stack<int> s2;
    void push(int value){
        s1.push(value);
    }
    int pop(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
         
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return value;
    }
};
