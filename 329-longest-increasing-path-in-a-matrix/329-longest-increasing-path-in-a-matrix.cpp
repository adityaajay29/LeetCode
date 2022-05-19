class Solution {
public:
    
    int dp[200][200]{};
    int maxPath, n, m;
    
    int solve(vector<vector<int>>& matrix, int i, int j, int prev)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= prev) 
            return 0;
        if(dp[i][j]) 
            return dp[i][j];
        return dp[i][j] = 1 + max({ solve(matrix, i + 1, j, matrix[i][j]),
                                    solve(matrix, i - 1, j, matrix[i][j]),
                                    solve(matrix, i, j + 1, matrix[i][j]),
                                    solve(matrix, i, j - 1, matrix[i][j]) });       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                maxPath = max(maxPath, solve(matrix, i, j, -1)); 
            }
        }
        return maxPath;
    }
};