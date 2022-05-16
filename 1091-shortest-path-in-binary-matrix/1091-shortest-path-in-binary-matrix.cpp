class Solution {
public:
    
    int visited[101][101];
    int distance[101][101];
    
    vector<int> dx{-1, 1, -1, 1, -1, 1, 0, 0};
    vector<int> dy{1, 1, -1, -1, 0, 0, -1, 1};
    
    bool isValid(int x, int y, int &n, vector<vector<int>> &grid)
    {
        if(x<0 || x>=n ||y<0 || y>=n)
            return false;
        if(visited[x][y])
            return false;
        if(grid[x][y] == 1)
            return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                distance[i][j]=INT_MAX;
                visited[i][j]=0;
            }
        }
        distance[0][0]=1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            if(x == n-1 && y == n-1)
                return distance[n-1][n-1];
            q.pop();
            for(int i=0;i<8;i++)
            {
                if(isValid(x+dx[i], y+dy[i], n, grid))
                {
                    visited[x+dx[i]][y+dy[i]]=1;
                    distance[x+dx[i]][y+dy[i]] = distance[x][y] + 1;
                    q.push({x+dx[i], y+dy[i]});
                }
            }
        }
        return -1;
    }
};