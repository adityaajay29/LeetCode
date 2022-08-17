class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int oranges = 0;
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != 0)
                    oranges++;
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int time = 0;
        int rotten = 0;
        while(!q.empty())
        {
            int sz = q.size();
            rotten += sz;
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    if(!isValid(x + dx[i], y + dy[i], m, n))
                        continue;
                    
                    if(grid[x + dx[i]][y + dy[i]] == 1)
                    {
                        grid[x + dx[i]][y + dy[i]] = 2;
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
            if(!q.empty())
                time++;
        }
        return (rotten == oranges ? time : -1);
    }
};