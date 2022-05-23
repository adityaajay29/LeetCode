class Solution {
public:
    
    int dp[101][101];
        
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(string s : strs)
        {
            int c0 = 0;
            int c1 = 0;
            for(char c : s)
            {
                (c == '0' ? c0++ : c1++);
            }
            for(int i=m;i>=c0;i--)
            {
                for(int j=n;j>=c1;j--)
                {
                    dp[i][j] = max(1 + dp[i-c0][j-c1], dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};