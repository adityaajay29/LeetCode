class Solution {
public:
    int solve(vector<int> &prices, int fees, int i, bool buy, vector<vector<int>> &dp)
    {
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
            return dp[i][buy] = max(-prices[i] + solve(prices, fees, i + 1, false, dp),
                                   solve(prices, fees, i + 1, true, dp));
        
        return dp[i][buy] = max(prices[i] - fees + solve(prices, fees, i + 1, true, dp),
                               solve(prices, fees, i + 1, false, dp));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        bool buy = true;
        return solve(prices, fee, 0, buy, dp);
    }
};