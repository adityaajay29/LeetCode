class Solution {
public:
    int mod = 1e9 + 7;
    
    long long solve(int n, int prev, vector<vector<int>> &dp)
    {
        if(n == 1)
            return 1;
        
        if(dp[n][prev] != -1)
            return dp[n][prev];
        
        long long res = 0;
        if(prev == 0)
        {
            res = (res + solve(n - 1, 1, dp)) % mod;
        }
        else if(prev == 1)
        {
            res = (res + solve(n - 1, 0, dp) + solve(n - 1, 2, dp)) % mod;
        }
        else if(prev == 2)
        {
            res = (res + solve(n - 1, 0, dp) + solve(n - 1, 1, dp) + solve(n - 1, 3, dp) + solve(n - 1, 4, dp)) % mod;
        }
        else if(prev == 3)
        {
            res = (res + solve(n - 1, 2, dp) + solve(n - 1, 4, dp)) % mod;
        }
        else 
            res = (res + solve(n - 1, 0, dp)) % mod;
        
        return dp[n][prev] = res;
    }
    
    int countVowelPermutation(int n) {
        
        long long res = 0;
        vector<vector<int>> dp(n + 1, vector<int> (5, -1));
        for(int i=0;i<5;i++)
        {
            res = (res + solve(n, i, dp)) % mod;
        }
        return (int)res;
    }
};