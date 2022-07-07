class Solution {
public:
    bool solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return true;
        
        if(i >= 0 && j < 0)
            return false;
        
        if(i < 0 && j >= 0)
        {
            for(int k=0;k<=j;k++)
            {
                if(s2[k] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j] || s2[j] == '?')
            return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
        
        if(s2[j] == '*')
        {
            bool keepStar = solve(s1, s2, i - 1, j, dp);
            bool ignoreStar = solve(s1, s2, i, j - 1, dp);
            return dp[i][j] = keepStar || ignoreStar;
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
        return solve(s, p, n1 - 1, n2 - 1, dp);
    }
};