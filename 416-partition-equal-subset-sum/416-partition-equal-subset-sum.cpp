class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, vector<vector<int>> &dp)
    {
        if(i == 0)
            return nums[0] == sum;
        
        if(sum == 0)
            return true;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        int notTake = solve(nums, i - 1, sum, dp);
        int take = false;
        
        if(nums[i] <= sum)
            take = solve(nums, i - 1, sum - nums[i], dp);
        
        return dp[i][sum] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums)
            sum += x;
        
        if(sum % 2)
            return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return solve(nums, n - 1, target, dp);
    }
};