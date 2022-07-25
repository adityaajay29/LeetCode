class Solution {
public:
    vector<int> dx{-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy{0, 1, 1, 1, 0, -1, -1, -1};
    
    bool isValid(int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y, int m, int n)
    {
        if(!isValid(x, y, m, n))
            return;
        
        if(board[x][y] == 'E')
        {
            int count = 0;
            for(int i=0;i<8;i++)
            {
                if(isValid(x + dx[i], y + dy[i], m, n) && board[x + dx[i]][y + dy[i]] == 'M')
                {
                    count++;
                }
            }
            if(count > 0)
            {
                board[x][y] = '0' + count;
            }
            else
            {
                board[x][y] = 'B';
                for(int i=0;i<8;i++)
                {
                    if(isValid(x + dx[i], y + dy[i], m, n))
                    {
                        dfs(board, x + dx[i], y + dy[i], m, n);
                    }
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y, m, n);
        return board;
    }
};