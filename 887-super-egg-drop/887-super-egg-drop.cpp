class Solution {
public:
    int solve(int eggs, int floors, vector<vector<int>> &dp)
    {
        if(floors == 0 || floors == 1)
            return floors;
        
        if(eggs == 1)
            return floors;
        
        if(dp[eggs][floors] != -1)
            return dp[eggs][floors];
        
        int moves = INT_MAX;
        
//         let the current floor be floor
        int l = 1, h = floors;
        while(l <= h)
        {
            int floor = l + (h - l) / 2;
            int breaks = solve(eggs - 1, floor - 1, dp);
            int notBreaks = solve(eggs, floors - floor, dp);
            
//             we have to minimise the moves in worst case
            int worstCase = 1 + max(breaks, notBreaks);
            if(breaks > notBreaks)
                h = floor - 1;
            else
                l = floor + 1;
            
            moves = min(moves, worstCase);
        }
        return dp[eggs][floors] = moves;
    }
    
    int superEggDrop(int eggs, int floors) {
        vector<vector<int>> dp(eggs + 1, vector<int> (floors + 1, -1));
        return solve(eggs, floors, dp);
    }
};