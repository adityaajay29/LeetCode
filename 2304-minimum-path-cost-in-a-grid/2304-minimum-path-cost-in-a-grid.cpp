class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (n));
        for(int j=0;j<n;j++)
        {
            dp[m-1][j] = grid[m-1][j];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int down = INT_MAX;
                for(int k=0;k<n;k++)
                {
                    int curr = moveCost[grid[i][j]][k] + dp[i + 1][k];
                    down = min(curr, down);
                }
                dp[i][j] = grid[i][j] + down;
            }
        }
        for(int j=0;j<n;j++)
        {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};