class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
//         base case
        for(int j=0;j<=amount;j++)
        {
            if(j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else dp[0][j] = INT_MAX - 1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int take = INT_MAX - 1;
                int notTake = dp[i-1][j];
                if(coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }
        return (dp[n-1][amount] == INT_MAX - 1 ? -1 : dp[n-1][amount]);
    }
};