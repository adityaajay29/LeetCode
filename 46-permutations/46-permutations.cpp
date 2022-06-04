class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> nums, int l, int h)
    {
        if(l == h)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=l;i<=h;i++)
        {
            swap(nums[l], nums[i]);
            solve(ans, nums, l+1, h);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(ans, nums, 0, n-1);
        return ans;
    }
};