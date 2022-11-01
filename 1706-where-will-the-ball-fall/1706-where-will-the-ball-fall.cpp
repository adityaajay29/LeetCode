class Solution {
public:
    int m, n;
    
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if(i >= m)
            return j;
        
        if(grid[i][j] == 1)
        {
            if(j == n - 1 || grid[i][j + 1] == -1)
                return -1;
            
            if(grid[i][j + 1] == 1)
                return solve(grid, i + 1, j + 1);
        }
        if(grid[i][j] == -1)
        {
            if(j == 0 || grid[i][j - 1] == 1)
                return -1;
            
            if(grid[i][j - 1] == -1)
                return solve(grid, i + 1, j - 1);
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        
        for(int j=0;j<n;j++)
        {
            ans[j] = solve(grid, 0, j);
        }
        return ans;
    }
};