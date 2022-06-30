class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n/2];
        int ans = 0;
        for(int x : nums)
        {
            ans += (abs(mid - x));
        }
        return ans;
    }
};