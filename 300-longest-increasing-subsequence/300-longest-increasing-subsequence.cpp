class Solution {
public:
    int dp[2501][2501];
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(auto x: nums)
            s.insert(x);
        vector<int> nums2{s.begin(), s.end()};
        int m = nums2.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};