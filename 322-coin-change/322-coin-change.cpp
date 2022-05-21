class Solution {
public:
    int dp[13][10001];
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i == 0)
                    dp[i][j] = INT_MAX-1;
                if(j == 0 && i!= 0)
                    dp[i][j] = 0;
            }
        }
        for(int j=1;j<=amount;j++)
        {
            dp[1][j] = (j % coins[0] == 0 ? j/coins[0] : INT_MAX-1);
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount]);
    }
};