class Solution {
public:
    int solve(string &s, int i, int n, vector<int> &dp)
    {
        if(i == n)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;
        
        if(s[i] != '0')
            ans += solve(s, i + 1, n, dp);
        
        if(i + 1 < n)
        {
            if(s[i] == '1' ||( s[i] == '2' && s[i + 1] <= '6'))
                ans += solve(s, i + 2, n, dp);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0')
            return 0;
        
        vector<int> dp(n, -1);
        
        return solve(s, 0, n, dp);
    }
};