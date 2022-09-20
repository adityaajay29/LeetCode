class Solution {
public:
    int ans = 0;
    
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        solve(nums1, nums2, i - 1, j, dp);
        solve(nums1, nums2, i, j - 1, dp);
        
        dp[i][j] = nums1[i] == nums2[j] ? 1 + solve(nums1, nums2, i - 1, j - 1, dp) : 0;
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(nums1 == nums2)
            return n1;
        
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
        solve(nums1, nums2, n1 - 1, n2 - 1, dp);
        return ans;
    }
};