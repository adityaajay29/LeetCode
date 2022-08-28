class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int pos = nums[0], neg = nums[0];
        for(int i=1;i<n;i++)
        {
            int temp = max({nums[i], nums[i] * pos, nums[i] * neg});
            neg = min({nums[i], nums[i] * pos, nums[i] * neg});
            pos = temp;
            
            res = max(res, pos);
        }
        return res;
    }
};