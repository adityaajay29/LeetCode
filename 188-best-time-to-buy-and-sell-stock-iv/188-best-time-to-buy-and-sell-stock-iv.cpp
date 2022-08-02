class Solution {
public:
    int solve(vector<int>& prices, int i, int k, bool buy, vector<vector<vector<int>>> &dp)
    {
        if(k == 0)
            return 0;
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        
        if(buy)
        {
            return dp[i][buy][k] = max(-prices[i] + solve(prices, i + 1, k, false, dp), 
                                      solve(prices, i + 1, k, true, dp));
        }
        return dp[i][buy][k] = max(prices[i] + solve(prices, i + 1, k - 1, true, dp),
                                    solve(prices, i + 1, k, false, dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        bool buy = true;
        return solve(prices, 0, k, buy, dp);
    }
};