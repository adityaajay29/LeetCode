class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cost = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int temp = nums[i - 1] * nums[k] * nums[j + 1] 
                        + solve(nums, i, k - 1, dp) 
                        + solve(nums, k + 1, j, dp);
            cost = max(cost, temp);
        }
        return dp[i][j] = cost;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(nums, 1, n, dp);
    }
};