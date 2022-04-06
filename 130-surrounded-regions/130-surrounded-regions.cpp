class Solution {
public:
    
    vector<int>dx{-1,0,0,1};
    vector<int>dy{0,1,-1,0};
    
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
        if(x<0 or y<0 or x>=m or y>=n or board[x][y] != 'O') return;
        board[x][y] = '#';
        for(int i=0;i<4;i++)
        {
            dfs(board,x+dx[i],y+dy[i],m,n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
    
        int m = board.size();
        
      if(m == 0) return;  
        
     int n = board[0].size();
     
     //Moving over firts and last column   
     for(int i=0; i<m; i++) {
         if(board[i][0] == 'O')
             dfs(board, i, 0, m, n);
         if(board[i][n-1] == 'O')
             dfs(board, i, n-1, m, n);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<n; j++) {
         if(board[0][j] == 'O')
             dfs(board, 0, j, m, n);
         if(board[m-1][j] == 'O')
             dfs(board, m-1, j, m, n);
     }
        
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
    }
};
