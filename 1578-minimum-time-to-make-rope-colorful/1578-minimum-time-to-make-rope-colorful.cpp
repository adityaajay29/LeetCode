class Solution {
public:
    int solve(string &colors, vector<int> &arr, int i, int m, vector<int> &dp)
    {
        if(i >= m)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int notMatch = INT_MAX, match = INT_MAX;
        if(i == 0 || colors[i] != colors[i - 1])
            notMatch = solve(colors, arr, i + 1, m, dp);
        else
        {
            colors[i - 1] = '*';
            if(arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
            match = min(arr[i], arr[i - 1]) + solve(colors, arr, i + 1, m, dp);
        }
        return dp[i] = min(match, notMatch);
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        int m = colors.size();
        vector<int> dp(m, -1);
        return solve(colors, neededTime, 0, m, dp);
    }
};

// BRBBBBGB
// 12321213

// BR*BBBGB - 2
// 123*1213
// BR**BBGB - 1
// BR***BGB - 2