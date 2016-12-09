题目描述


Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). 

class Solution {
public:
    //时间复杂度Ｏ(n),空间复杂度Ｏ(n)
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        const int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        for(int i = 1, vally = prices[0]; i < n; i++){
            vally = min(vally, prices[i]);
            f[i] = max(f[i-1], prices[i]-vally);
        }
        
        for(int j = n-2, peak = prices[n-1]; j >= 0; j--){
            peak = max(peak, prices[j]);
            g[j] = max(g[j], peak - prices[j]);
        }
        
        int max_profit = 0;
        for(int k = 0; k < n; k++){
            max_profit = max(max_profit, f[k]+g[k]);
        }
        return max_profit;
    }
};
