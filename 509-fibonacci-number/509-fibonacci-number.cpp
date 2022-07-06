class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int f1 = 0;
        if(n - 1 >= 0)
            f1 = solve(n - 1, dp);
        int f2 = 0;
        if(n - 2 >= 0)
            f2 = solve(n - 2, dp);
        
        return dp[n] = f1 + f2;
    }
    
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};