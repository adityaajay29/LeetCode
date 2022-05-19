class Solution {
public:
    
    int dp[14][10002];
    
    int topDown(vector<int> &coins, int n, int amount)
    {
        if(n == 0)
            return (amount == 0 ? 0 : INT_MAX-1);
        if(dp[n][amount] != -1)
            return dp[n][amount];
        if(coins[n-1] <= amount)
            return dp[n][amount] = min(1 + topDown(coins, n, amount-coins[n-1]), topDown(coins, n-1, amount));
        else
            return dp[n][amount] = topDown(coins, n-1, amount);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp, -1, sizeof(dp));
        return (topDown(coins, n, amount) == INT_MAX-1 ? -1 : topDown(coins, n, amount));
    }
};