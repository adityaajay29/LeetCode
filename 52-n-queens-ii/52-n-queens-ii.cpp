class Solution {
public:
    bool isValid(int row, int col, vector<string> board, int n)
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
        while(j >=0)
        {
            if(board[i][j] == 'Q')
                return false;
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
        
        return true;
    }
    
    void solve(int &ans, vector<string> &board, int col, int n)
    {
        if(col == n)
        {
            ans++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(ans, board, col + 1, n);
                board[row][col] = 'x';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, 'x');
        for(int i=0;i<n;i++)
            board[i] = s;
        
        int ans = 0;
        solve(ans, board, 0, n);
        return ans;
    }
};