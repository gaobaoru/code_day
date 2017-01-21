题目描述

There are N children standing in a line. Each child is assigned a rating value. 

You are giving candies to these children subjected to the following requirements: 
Each child must have at least one candy. 
Children with a higher rating get more candies than their neighbors. 

What is the minimum candies you must give? 

时间复杂度O（n）,空间复杂度O（n）
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> increment(n);
        for(int i = 1, inc = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        
        for(int i = n-2, inc = 1; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                increment[i] = max(inc++, increment[i]);
            else
                inc = 1;
        }
        
        return accumulate(&increment[0], &increment[0]+n, n);
    }
};
