class Solution {
public:
    int distance[101][101];
    vector<int>dx{-1,0,1,0};
    vector<int>dy{0,1,0,-1};
    
    bool isValid(int x,int y,int &m,int &n)
    {
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
      
    int bfs(vector<vector<int>>& heights,int x,int y,int &m,int &n)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==m-1 && y==n-1)
                return wt;
            for(int i=0;i<4;i++)
            {
                if(isValid(x+dx[i],y+dy[i],m,n))
                {
                    int a=x+dx[i];
                    int b=y+dy[i];
                    int newCost=max(wt,abs(heights[a][b]-heights[x][y]));
                    if(distance[a][b]>newCost)
                    {
                        distance[a][b]=newCost;
                        pq.push({distance[a][b],{a,b}});
                    }
                }
            }
        }
        return 0;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                distance[i][j]=INT_MAX;
            }
        }
        distance[0][0]=0;
        return bfs(heights,0,0,m,n);
    }
};