class Solution {
public:
    int modulo = 1e9 + 7;
    
    int solve(int m, int n, int i, int j, int moves, vector<vector<vector<int>>> &dp)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        
        if(moves == 0)
            return 0;
        
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        
        long long left = solve(m, n, i - 1, j, moves - 1, dp);
        long long right = solve(m, n, i + 1, j, moves - 1, dp);
        long long up = solve(m, n, i, j - 1, moves - 1, dp);
        long long down = solve(m, n, i,j + 1, moves - 1, dp);
        
        return dp[i][j][moves] = (left + right + down + up) % modulo;
    }   
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        return solve(m, n, startRow, startColumn, maxMove, dp);
    }
};