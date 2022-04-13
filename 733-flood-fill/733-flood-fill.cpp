class Solution {
public:
    
    vector<int>dx{-1,0,0,1};
    vector<int>dy{0,-1,1,0};
    int visited[51][51];
    
    bool isvalid(int &m,int &n,int x,int y,vector<vector<int>>& image, int sr, int sc)
    {
        if(x<0 || x>=m || y<0 || y>=n || visited[x][y])
            return false;
        // if(image[x][y]!=image[sr][sc])
        //     return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // vector<vector<int>>v;
        // v=image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int temp=image[sr][sc];
        image[sr][sc]=-1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xNext=x+dx[i];
                int yNext=y+dy[i];
                if(isvalid(m,n,xNext,yNext,image,sr,sc))
                {
                    if(image[xNext][yNext]==-1 || image[xNext][yNext]==temp)
                    {
                        image[xNext][yNext]=-1;
                        visited[xNext][yNext]=1;
                        q.push({xNext,yNext});
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]==-1)
                    image[i][j]=newColor;
            }
        }
        return image;
    }
};