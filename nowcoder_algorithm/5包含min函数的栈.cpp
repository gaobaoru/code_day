定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。 

public:
    void push(int value) {
        stackData.push(value);
        if(stackMin.empty())
            stackMin.push(value);
        else{
            if(value < stackMin.top())
                stackMin.push(value);
            else
                stackMin.push(stackMin.top());
        }
    }
    void pop() {
        stackData.pop();
        stackMin.pop();
    }
    int top() {
        return stackData.top();
    }
    int min() {
        return stackMin.top();
    }
private:
    stack<int> stackData;
    stack<int> stackMin;
};
