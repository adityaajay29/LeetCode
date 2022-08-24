class Solution {
public:
    int findMin(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 0, nums.end());
        return nums[0];
    }
};