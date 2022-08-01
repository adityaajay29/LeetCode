class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int> (n, 1));
        vector<int> prev(n, 1);
        for(int i=1;i<m;i++)
        {
            vector<int> curr(n, 1);
            for(int j=1;j<n;j++)
            {
                int left = curr[j - 1];
                int up = prev[j];
                curr[j] = left + up;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};