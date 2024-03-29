class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i == 0)
            return j;
        
        if(j == 0)
            return i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1])
            return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
        
        int a = solve(s1, s2, i - 1, j, dp);
        int b = solve(s1, s2, i, j - 1, dp);
        int c = solve(s1, s2, i - 1, j - 1, dp);
        
        return dp[i][j] = 1 + min({a, b, c});
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return solve(word1, word2, n1, n2, dp);
    }
};