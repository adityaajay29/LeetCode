class Solution {
public:
    int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
    {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
        {
            return dp[i][buy] = max(-prices[i] + solve(prices, i + 1, false, dp), 
                        0 + solve(prices, i + 1, true, dp));
        }
//         else
        return dp[i][buy] = max(prices[i] + solve(prices, i + 2, true, dp), 
                    0 + solve(prices, i + 1, false, dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy == 1)
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0],
                                        0 + dp[i + 1][1]);
                else
                    dp[i][buy] = max(prices[i] + dp[i + 2][1], 
                                        0 + dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }
};