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
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    if(isValid(i+dx[k],j+dy[k],m,n))
                    {
                        if(board[i+dx[k]][j+dy[k]]==1 || board[i+dx[k]][j+dy[k]]==2)
                        count++;
                    }
                }
                if(board[i][j]==1)
                {
                    if(count<2)
                    {
                        board[i][j]=2;
                    }
                    
                    else if(count>3)
                    {
                        board[i][j]=2;
                    }
                }
                else if(board[i][j]==0)
                {
                    if(count==3)
                    {
                        board[i][j]=3;
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==2)
                    board[i][j]=0;
                else if(board[i][j]==3)
                    board[i][j]=1;
            }
        }
    }
};