class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int j = 0;j<n;j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            int m = triangle[i].size();
            for(int j=m-1;j>=0;j--)
            {
                int down = dp[i+1][j];
                int diag = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        return dp[0][0];
    }
};