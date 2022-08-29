class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return false;
        
        if(grid[x][y] == '0' || visited[x][y])
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y)
    {
        visited[x][y] = 1;
        for(int i=0;i<4;i++)
        {
            if(isValid(grid, visited, x + dx[i], y + dy[i]))
                dfs(grid, visited, x + dx[i], y + dy[i]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int count = 0;
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(isValid(grid, visited, x, y))
                {
                    count++;
                    dfs(grid, visited, x, y);
                }
            }
        }
        return count;
    }
};