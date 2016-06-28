题目描述

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 

The replacement must be in-place, do not allocate extra memory. 

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3→1,3,2
 3,2,1→1,2,3
 1,1,5→1,5,1 
 
 时间复杂度O（n）,空间复杂度O（1）
 class Solution {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(),num.end());
    }
    
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last){
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);
        auto pivot = next(rfirst);
        while(pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;
        if(pivot == rlast){
            reverse(rfirst,rlast);
            return false;
        }
        auto point = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*point, *pivot);
        reverse(rfirst, pivot);
        
        return true;
    }
};
