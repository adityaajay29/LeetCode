class Solution {
public:
    int solve(int floors, int eggs, vector<vector<int>> &dp)
    {
        if(floors == 0 || floors == 1)
            return floors;
        
        if(eggs == 1)
            return floors;
        
        if(dp[floors][eggs] != -1)
            return dp[floors][eggs];
        
        int moves = INT_MAX;
        for(int floor = 1; floor <= floors; floor++)
        {
            int breaks = solve(floor - 1, eggs - 1, dp);
            int notBreaks = solve(floors - floor, eggs, dp);
            int worstCase = 1 + max(breaks, notBreaks);
            moves = min(moves, worstCase);
        }
        return dp[floors][eggs] = moves;
    }
    
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (3, -1));
        return solve(n, 2, dp);
    }
};