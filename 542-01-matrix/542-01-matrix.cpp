class Solution {
public:
    
    vector<int>dx{-1,0,0,1};
    vector<int>dy{0,1,-1,0};
    
    bool isValid(vector<vector<int> >& mat,int m,int n,int x,int y)
                 {
                     if(x<0 || x>=m || y<0 || y>=n)
                         return false;
                    
                     return true;
                 }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int> > dist(m,vector<int>(n,-1));
        queue<pair<int,int> >q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }    
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isValid(mat,m,n,x+dx[i],y+dy[i]))
                {
                    if(dist[x+dx[i]][y+dy[i]]==-1)
                    {
                        dist[x+dx[i]][y+dy[i]]=1+dist[x][y];
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
        return dist;
    }
};