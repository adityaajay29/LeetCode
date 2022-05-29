class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
            return grid[0][0];
        
        if(i < 0 || j < 0)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = INT_MAX;
        int up = INT_MAX;
        
        if(i > 0)
            up = solve(grid, i-1, j, dp);
        
        if(j > 0)
            left = solve(grid, i, j-1, dp);
        
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};