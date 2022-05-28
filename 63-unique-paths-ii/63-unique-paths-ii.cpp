class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = 0;
        int left = 0;
        
        if(i > 0 && grid[i-1][j] != 1)
            up = solve(i-1, j, grid, dp);
        
        if(j > 0 && grid[i][j-1] != 1)
            left = solve(i, j-1, grid, dp);
        
        return dp[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return solve(m-1, n-1, obstacleGrid, dp);
    }
};