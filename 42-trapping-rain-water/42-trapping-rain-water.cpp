class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int lMax = nums[0], hMax = nums[n - 1];
        int l = 0, h = n - 1;
        int ans = 0;
        while(l < h)
        {
            if(nums[h] > nums[l])
            {
                if(nums[l] > lMax)
                    lMax = nums[l];
                else
                    ans += lMax - nums[l];
                l++;
            }
            else
            {
                if(nums[h] > hMax)
                    hMax = nums[h];
                else
                    ans += hMax - nums[h];
                h--;
            }
        }
        return ans;
    }
};