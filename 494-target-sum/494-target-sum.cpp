class Solution {
public:
    int solve(vector<int> &nums, int i, int sum, vector<vector<int>> &dp)
    {
        if(i == 0)
        { 
            if(nums[0] == 0 && sum == 0)
                return 2;
            
            if(nums[0] == sum || sum == 0)
                return 1;
            
            return 0;
        }
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        int take = 0;
        int notTake = solve(nums, i - 1, sum, dp);
        if(nums[i] <= sum)
        {
            take = solve(nums, i - 1, sum - nums[i], dp);
        }
        return dp[i][sum] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int x : nums)
            totalSum += x;
        
        if(totalSum - target < 0 || (totalSum - target) % 2)
            return 0;
        
        int sum = (totalSum - target)/2;
        
        vector<vector<int>> dp(n, vector<int> (sum + 1));
        
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        
        if(nums[0] <= sum && nums[0] != 0)
            dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int take = 0;
                int notTake = dp[i-1][j];
                if(nums[i] <= j)
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][sum];
    }
};