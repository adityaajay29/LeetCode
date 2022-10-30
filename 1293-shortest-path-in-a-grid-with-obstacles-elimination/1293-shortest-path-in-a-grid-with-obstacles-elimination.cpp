class Solution {
public:
    int solve(int i,int j,int k,vector<vector<int>> &grid,vector<vector<int>> &visited, 
 vector<vector<vector<int>>> &dp)    
    {
        if(i == 0 && j == 0)
            return dp[i][j][k] = 0;

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j])
            return 1e6;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        if(grid[i][j] == 1)
        {
            if(k==0)
                return 1e6;

            k--;
        }

        visited[i][j] = 1;

        int up = 1 + solve(i - 1, j, k, grid, visited, dp);
        int left = 1 + solve(i, j - 1, k,grid, visited, dp);
        int down = 1 + solve(i + 1, j, k, grid, visited, dp);
        int right = 1 + solve(i, j + 1, k, grid, visited, dp);

        visited[i][j] = 0;

        return dp[i][j][k] = min({up, left, right, down});
    }
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size(),n = grid[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = solve(m - 1, n - 1, k, grid, visited, dp);

        return (ans > m * n) ? -1 : ans;             
    }
};