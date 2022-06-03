class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> temp, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        solve(nums, ans, temp, i+1);
        temp.push_back(nums[i]);
        solve(nums, ans, temp, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, {}, 0);
        return ans;
    }
};