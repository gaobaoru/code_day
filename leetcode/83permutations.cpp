题目描述


Given a collection of numbers, return all possible permutations.

For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1]. 

class Solution {
public:
    //时间复杂度O(n!),空间复杂度O(1)
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do{
            result.push_back(num);
        }while(next_permutation(num.begin(), num.end()));
        return result;
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
