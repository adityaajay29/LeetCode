class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = solve(i, j - 1, dp);
        int up = solve(i - 1, j, dp);
        
        return dp[i][j] = left + up;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        // return solve(m - 1, n - 1, dp);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int left = dp[i][j - 1];
                int up = dp[i - 1][j];
                dp[i][j] = left + up;
            }
        }
        return dp[m - 1][n - 1];
    }
};