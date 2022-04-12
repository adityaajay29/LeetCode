class Solution {
public:
    
    vector<int>dx{1,-1,0,0,1,1,-1,-1};
    vector<int>dy{0,0,-1,1,-1,1,-1,1};
    
    bool isValid(int x,int y,int m,int n)
    {
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>v;
        v=board;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    if(isValid(i+dx[k],j+dy[k],m,n))
                    {
                        if(board[i+dx[k]][j+dy[k]]==1)
                        count++;
                    }
                }
                if(board[i][j]==1)
                {
                    if(count<2)
                    {
                        v[i][j]=0;
                    }
                    else if(count==2 || count==3)
                    {
                        v[i][j]=1;
                    }
                    else if(count>3)
                    {
                        v[i][j]=0;
                    }
                }
                else
                {
                    if(count==3)
                    {
                        v[i][j]=1;
                    }
                }
            }
        }
        board=v;
    }
};
