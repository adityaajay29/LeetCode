class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(vector<vector<int>>& grid, vector<vector<int>> &visited, int m, int n, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(visited[i][j])
            return false;
        
        if(grid[i][j] == 0)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int m, int n, int i, int j, int &count)
    {
        visited[i][j] = 1;
        count++;
        for(int k=0;k<4;k++)
        {
            if(isValid(grid, visited, m, n, i + dx[k], j + dy[k]))
            {
                dfs(grid, visited, m, n, i + dx[k], j + dy[k], count);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int maxArea = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count = 0;
                if(isValid(grid, visited, m, n, i, j))
                {
                    dfs(grid,visited, m, n, i, j, count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
};