class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
//         if we matched all chars of t in s, then only we reached here
        if(j == 0)
            return 1;
        
//         if s exhausted and t still has some char to match, means match isnt there anymore
        if(i == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i - 1] == t[j - 1])
//             if matching, there can be two cases : 
//             either take the curr matching and move to next char in s and t both 
//             or search for any other match in s for the same matching char
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
        
//         if not matching, then definitly look if there is other match of curr char of t in s
        return dp[i][j] = solve(s, t, i - 1, j, dp);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m + 1, vector<double> (n + 1, 0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0] = 1;
        }
        
//         we start from j = 1, as, dp[0][0] should be 1, i.e., when both strings have exhausted
//         meaning there was a match 
        for(int j=1;j<=n;j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[m][n];
    }
};