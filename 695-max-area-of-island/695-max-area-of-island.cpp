class Solution {
public:
    int visited[51][51];
    vector<int>dx{-1,0,0,1};
    vector<int>dy{0,1,-1,0};
    
    bool isValid(vector<vector<int>>& grid,int x,int y,int m,int n)
    {
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        if(visited[x][y] || grid[x][y]==0)
            return false;
        return true;
    }
    
    void area(vector<vector<int>>& grid,int x,int y,int m,int n,int &count)
    {
        visited[x][y]=1;
        count++;
        for(int i=0;i<4;i++)
        {
            if(isValid(grid,x+dx[i],y+dy[i],m,n))
                area(grid,x+dx[i],y+dy[i],m,n,count);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                if(!visited[i][j] && grid[i][j]==1)
                    area(grid,i,j,m,n,count);
                ans=max(ans,count);
            }
        }
        return ans;
    }
};