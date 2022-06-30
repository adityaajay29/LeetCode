class Solution {
public:
    int minMoves(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 0, nums.end());
        int min = nums[0];
        int ans = 0;
        for(int x : nums)
        {
            ans += (x - min);
        }
        return ans;
    }
};