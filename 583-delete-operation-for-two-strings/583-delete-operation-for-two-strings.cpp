class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1])
        {
            return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
        }
    
        return  dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
    }
    
    int minDistance(string word1, string word2) {
        if(word1 == word2)
            return 0;
        
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return (n1 + n2 - 2 * solve(word1, word2, n1, n2, dp));
    }
};