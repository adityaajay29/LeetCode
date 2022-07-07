class Solution {
public:
    int dp[202][202][202];
    
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if(i < 0 && j < 0 && k < 0)
            return true;
        
        if(i < 0 && j >= 0)
        {
            for(int it = 0;it<=j;it++)
            {
                if(s2[it] != s3[it])
                    return false;
            }
            return true;
        }
        
        if(i >= 0 && j < 0)
        {
            for(int it = 0;it<=i;it++)
            {
                if(s1[it] != s3[it])
                    return false;
            }
            return true;
        }
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        bool one = false;
        bool two = false;
        bool both = false;
        if(s1[i] == s3[k] && s2[j] != s3[k])
        {
            one = solve(s1, s2, s3, i - 1, j, k - 1);
        }
        else if(s2[j] == s3[k] && s1[i] != s3[k])
        {
            two = solve(s1, s2, s3, i, j - 1, k - 1);
        }
        else if(s1[i] == s3[k] && s2[j] == s3[k])
        {
            both = solve(s1, s2, s3, i - 1, j, k - 1) || solve(s1, s2, s3, i, j - 1, k - 1);
        }
        return dp[i][j][k] = one || two || both;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if(n1 + n2 != n3)
            return false;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1);
    }
};