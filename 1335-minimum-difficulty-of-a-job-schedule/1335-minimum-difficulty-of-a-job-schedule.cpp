class Solution {
public:
    int solve(vector<int> &arr, int days, int i, int n, vector<vector<int>> &dp)
    {
        if(days == 0 && i == n)
            return 0;
        
        if(days == 0 || i == n)
            return 1e9;
        
        if(dp[i][days] != -1)
            return dp[i][days];
       
        int curr = -1e9;
        int mini = 1e9;
        for(int k = i;k<n;k++)
        {
            curr = max(curr, arr[k]);
            mini = min(mini, curr + solve(arr, days - 1, k + 1, n, dp));
        }
        return dp[i][days] = mini;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        
        vector<vector<int>> dp(n, vector<int> (d + 1, -1));
        return solve(jobDifficulty, d, 0, n, dp);
    }
};

