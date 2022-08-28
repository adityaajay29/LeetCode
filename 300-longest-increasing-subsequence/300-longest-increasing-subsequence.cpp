class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][j + 1] != -1)
            return dp[i][j + 1];
        
        int notTake = solve(nums, i + 1, j, dp);
        int take = INT_MIN;
        
        if(j == -1 || nums[i] > nums[j])
            take = 1 + solve(nums, i + 1, i, dp);
        
        return dp[i][j + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};