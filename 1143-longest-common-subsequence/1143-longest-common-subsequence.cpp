class Solution {
public:
    int solve(string &s1, string &s2, int i,int j, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
    
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
        
        return dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solve(text1, text2, n1 - 1, n2 - 1, dp);
    }
};