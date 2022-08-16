class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int l, int h)
    {
        if(l == h)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=l;i<=h;i++)
        {
            swap(nums[l], nums[i]);
            solve(nums, ans, l + 1, h);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(nums, ans, 0, n - 1);
        
        return ans;
    }
};