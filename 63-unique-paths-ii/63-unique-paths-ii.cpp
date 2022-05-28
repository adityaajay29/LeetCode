class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)
                dp[i][j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;

                    if(i > 0 && grid[i-1][j] != 1)
                    up = dp[i-1][j];

                    if(j > 0 && grid[i][j-1] != 1)
                    left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int> (n));
        
        return solve(m, n, obstacleGrid, dp);
    }
};