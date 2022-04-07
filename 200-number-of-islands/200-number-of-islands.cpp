class Solution {
public:
    
    int visited[301][301];
    vector<int>dx{-1,0,0,1};
    vector<int>dy{0,1,-1,0};
    
    bool isValid(vector<vector<char>>& grid,int m,int n,int x,int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        if(visited[x][y] || grid[x][y]=='0')
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>>& grid,int m,int n,int x,int y)
    {
        visited[x][y]=1;
        for(int i=0;i<4;i++)
        {
            if(isValid(grid,m,n,x+dx[i],y+dy[i]))
                dfs(grid,m,n,x+dx[i],y+dy[i]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(grid,m,n,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};