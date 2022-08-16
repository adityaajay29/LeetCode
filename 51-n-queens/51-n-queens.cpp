class Solution {
public:
    bool isValid(vector<string> &board, int row, int col)
    {
        int i = row, j = col;
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            
            i--, j--;
        }
        i = row, j = col;
        while(j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            
            j--;
        }
        j = col;
        while(i < board.size() && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            
            i++, j--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
    {
        if(col == n)
        {
            ans.push_back(board);
                return;
        }
        for(int row=0;row<n;row++)
        {
            if(board[row][col] == '.')
            {
                if(isValid(board, row, col))
                {
                    board[row][col] = 'Q';
                    solve(ans, board, n, col + 1);
                    board[row][col] = '.';
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s;
        for(int i=0;i<n;i++)
            s.push_back('.');
        for(int i=0;i<n;i++)
            board.push_back(s);
        
        solve(ans, board, n, 0);
        
        return ans;
    }
};