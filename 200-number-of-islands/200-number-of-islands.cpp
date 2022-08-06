class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(visited[i][j] || grid[i][j] == '0')
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int m, int n)
    {
        visited[x][y] = 1;
        for(int i=0;i<4;i++)
        {
            if(isValid(grid, visited, x + dx[i], y + dy[i], m, n))
                dfs(grid, visited, x + dx[i], y + dy[i], m, n);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isValid(grid, visited, i, j, m, n))
                {
                    count++;
                    dfs(grid, visited, i, j, m, n);
                }
            }
        }
        return count;
    }
};