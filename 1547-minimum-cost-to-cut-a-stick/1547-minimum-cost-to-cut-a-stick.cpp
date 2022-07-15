class Solution {
public:
    int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int part = cuts[j + 1] - cuts[i - 1] + solve(cuts, i, k - 1, dp) + solve(cuts, k + 1, j, dp);
            mini = min(mini, part);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        vector<int> arr = cuts;
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin(), arr.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz + 1, vector<int> (sz + 1, -1));
        return solve(arr, 1, sz, dp);
    }
};