

对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么它就是树根。请设计O(n)的算法实现这个方法。

给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。
测试样例：

[3,1,4,2],4

返回：[2,0,-1,2]

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
    vector<int> vec(n, -1);
    stack<int> s;
   
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && A[i] > A[s.top()])
        {
            if(vec[s.top()] == -1 || A[i] < A[vec[s.top()]])
                vec[s.top()] = i;
            s.pop();
        }
   
        if(!s.empty())
            vec[i]  = s.top();
        s.push(i);
    }
    return vec;
}
};
