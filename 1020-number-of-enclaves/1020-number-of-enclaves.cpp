class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(vector<vector<int>>& grid, int i,int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(grid[i][j] == 0)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        grid[x][y] = 0;
        for(int i=0;i<4;i++)
        {
            if(isValid(grid, x + dx[i], y + dy[i], m, n))
                dfs(grid, x + dx[i], y + dy[i], m, n);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                {
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};