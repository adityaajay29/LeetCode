class Solution {
public:
    
    int solve(vector<int> &nums, vector<int> &multi, int l, int k, vector<vector<int>> &dp)
    {
        if(k == multi.size())
            return 0;
        
        if(l == nums.size())
            return 0;
        
        if(dp[l][k] != INT_MIN)
            return dp[l][k];
        
        int front = nums[l] * multi[k] + solve(nums, multi, l + 1, k + 1, dp);
//         right = nums.size - (k - left)
        int back = nums[nums.size() - 1 - (k - l)] * multi[k] + solve(nums, multi, l, k + 1, dp);      
        return dp[l][k] = max(front, back);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, INT_MIN));
        return solve(nums, multipliers,0, 0, dp);
    }
};
