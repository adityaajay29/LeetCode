class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int h = 0;
        int sum = 0;
        unordered_set<int> s;
        while(l < n && h < n)
        {
            if(s.find(nums[h]) == s.end())
            {
                s.insert(nums[h]);
                sum += nums[h++];
            }
            else
            {
                s.erase(nums[l]);
                sum -= nums[l++];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};