class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));
        vector<int> prev(n, 0);
        for(int j = 0;j<n;j++)
        {
            prev[j] = triangle[n - 1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            int m = triangle[i].size();
            vector<int> curr(m, 0);
            for(int j=m-1;j>=0;j--)
            {
                int down = prev[j];
                int diag = prev[j+1];
                curr[j] = triangle[i][j] + min(down, diag);
            }
            prev.resize(m);
            prev = curr;
        }
        return prev[0];
    }
};