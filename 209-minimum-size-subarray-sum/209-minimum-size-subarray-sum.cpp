class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int h = 0;
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        while(l < n && h <= n)
        {
            if(sum < target && h < n)
            {
                sum += nums[h++];
            }
            else
            {
                sum -= nums[l++];
            }
            if(sum >= target)
            {
                ans = min(ans, (h - l));
            }
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};