题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
    //时间复杂度O(n),空间复杂度O(n)
    void reOrderArray(vector<int> &array) {
        if(array.empty()) return;
        vector<int> array_tmp;
        vector<int>::iterator itor, itor_tmp;
        for(auto itor = array.begin(); itor != array.end();){
            if((*itor % 2) == 0){
                array_tmp.push_back(*itor);
                itor = array.erase(itor);
            }else{
                itor++;
            }
        }
        for(auto itor_tmp = array_tmp.begin(); itor_tmp != array_tmp.end(); itor_tmp++){
            array.push_back(*itor_tmp);
        }
    }
};

