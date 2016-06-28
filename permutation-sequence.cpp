题目描述

The set[1,2,3,…,n]contains a total of n! unique permutations. 

By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3): 
"123" 
"132" 
"213" 
"231" 
"312" 
"321" 

Given n and k, return the k th permutation sequence. 

Note: Given n will be between 1 and 9 inclusive. 

康拓编码示例:
如何找出第16个（按字典序的）{1,2,3,4,5}的全排列？ 
  
1. 首先用16-1得到15 
  
2. 用15去除4! 得到0余15 
  
3. 用15去除3! 得到2余3 
  
4. 用3去除2! 得到1余1 
  
5. 用1去除1! 得到1余0 
  
有0个数比它小的数是1，所以第一位是1 
  
有2个数比它小的数是3，但1已经在之前出现过了所以是4 
  
有1个数比它小的数是2，但1已经在之前出现过了所以是3 
  
有1个数比它小的数是2，但1,3,4都出现过了所以是5 
  
最后一个数只能是2 
  
所以排列为1 4 3 5 2 

时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        string result;
        for(int i=0; i<n; i++)
            s[i] += i+1;
        
        return kth_permutation(s, k);
    }
private:
    int factorial(int n){
        int result = 1;
        for(int i=1; i<=n; i++)
            result *= i;
        return result;
    }
    
    string kth_permutation(const string& seq, int k){
        const int n = seq.size();
        string S(seq);
        string result;
        
        int base = factorial(n-1);
        k--;
        for(int i=n-1; i>0; k %= base, base /= i, i--){
            auto a = next(S.begin(), k/base);
            result.push_back(*a);
            S.erase(a);
        }
        result.push_back(S[0]);
        return result;
    }
};
