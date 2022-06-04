class Solution {
public:
    
    bool isValid(vector<string> board, int row, int col, int n)
    {
        int i = row;
        int j = col;
        
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        
        i = row;
        j = col;
        
        while(i < n && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        
        i = row;
        j = col;
        
        while(j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            j--;
        }
        
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> board, int col, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isValid(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(ans, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        
        solve(ans, board, 0, n);
        
        return ans;
    }
};