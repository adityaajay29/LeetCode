class Solution {
public:
    int solve(vector<int> &cost, int i, vector<int> &dp)
    {
        if(i > cost.size() - 1)
            return 0;
        
        if(i == cost.size() - 1)
            return cost.back();
        
        if(dp[i] != -1)
            return dp[i];
        
        int oneStep = solve(cost, i + 1, dp);
        int twoStep = solve(cost, i + 2, dp);
        
        return dp[i] = cost[i] + min(oneStep, twoStep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int zero = solve(cost, 0, dp);
        for(int x : dp)
            x = -1;
        int one = solve(cost, 1, dp);
        return min(zero, one);
    }
};