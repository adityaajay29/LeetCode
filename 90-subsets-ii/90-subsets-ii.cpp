class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int i)
    {
        ans.push_back(temp);
        
        for(int j=i;j<nums.size();j++)
        {
            if(j != i && nums[j] == nums[j - 1])
                continue;
            
            temp.push_back(nums[j]);
            solve(nums, ans, temp, j + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(nums, ans, {}, 0);
        return ans;
    }
};