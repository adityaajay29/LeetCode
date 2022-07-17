class Solution {
public:
    double solve(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 1.0;
        
        if(k == 0)
            return 0.0;
        
        if(dp[k][i][j] != -1.0)
            return dp[k][i][j];
        
        double a = solve(n, k - 1, i - 1, j - 2, dp);
        double b = solve(n, k - 1, i - 2, j - 1, dp);
        double c = solve(n, k - 1, i - 2, j + 1, dp);
        double d = solve(n, k - 1, i - 1, j + 2, dp);
        double e = solve(n, k - 1, i + 1, j + 2, dp);
        double f = solve(n, k - 1, i + 2, j + 1, dp);
        double g = solve(n, k - 1, i + 2, j - 1, dp);
        double h = solve(n, k - 1, i + 1, j - 2, dp);
        
        return dp[k][i][j] = (a + b + c + d + e + f + g + h) / 8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n, vector<double> (n, -1.0)));
        return 1 - solve(n, k, row, column, dp);
    }
};