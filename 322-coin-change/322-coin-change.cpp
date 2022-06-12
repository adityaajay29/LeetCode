class Solution {
public:
    int solve(vector<int> &coins, int i, int val, vector<vector<int>> &dp)
    {
        if(i == 0)
        {
            if(val % coins[0] == 0)
                return val / coins[0];
            return INT_MAX - 1;
        }
        
        if(dp[i][val] != -1)
            return dp[i][val];
        
        int take = INT_MAX - 1;
        int notTake = 0 + solve(coins, i - 1, val, dp);
        if(coins[i] <= val)
        {
            take = 1 + solve(coins, i, val - coins[i], dp);
        }
        return dp[i][val] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = solve(coins, n - 1, amount, dp);
        return (ans == INT_MAX - 1 ? -1 : ans);
    }
};