class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    
    bool isValid(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(grid[i][j] != 1)
            return false;
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int oranges = 0;
        int count = 0;
        int time = 0;

        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if(grid[i][j] != 0)
                    oranges++;
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            count += size;
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    if(isValid(grid, x + dx[i], y + dy[i], m, n))
                    {
                        grid[x + dx[i]][y + dy[i]] = 2;
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
            if(!q.empty())
                time++;
        }
        return (oranges == count ? time : -1);
    }
};