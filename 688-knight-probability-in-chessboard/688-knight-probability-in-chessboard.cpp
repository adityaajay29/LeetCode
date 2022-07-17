class Solution {
public:
    vector<int> dx{-1, -2, -2, -1, 1, 2, 2, 1};
    vector<int> dy{-2, -1, 1, 2, 2, 1, -1, -2};
    
    double solve(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 1.0;
        
        if(k == 0)
            return 0.0;
        
        if(dp[k][i][j] != -1.0)
            return dp[k][i][j];
        
        double move = 0;
        
        for(int it=0;it<8;it++)
        {
            int x = i + dx[it];
            int y = j + dy[it];
            
            move += solve(n, k - 1, x, y, dp);
        }
        return dp[k][i][j] = move / 8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n, vector<double> (n, -1.0)));
        return 1 - solve(n, k, row, column, dp);
    }
};