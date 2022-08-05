class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(int i, int j, int m, int n)
    {
        return !(i < 0 || i >= m || j < 0 || j >= n);
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, int m, int n, string word, int k)
    {
        if(k == word.size())
            return true;
        
        char c = board[x][y];
        board[x][y] = '*';
        for(int i=0;i<4;i++)
        {
            if(isValid(x + dx[i], y + dy[i], m, n))
            {
                if(board[x + dx[i]][y + dy[i]] == word[k])
                {
                    if(dfs(board, x + dx[i], y + dy[i], m, n, word, k + 1))
                        return true;
                }
            }
        }
        board[x][y] = c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int sz = word.size();
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, i, j, m, n, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};