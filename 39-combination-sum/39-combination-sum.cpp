class Solution {
public:
    void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int>temp, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(i == arr.size())
            return;
        
        if(arr[i] <= target)
        {
            temp.push_back(arr[i]);
            solve(arr, ans, temp, target - arr[i], i);
            temp.pop_back();
        }
        solve(arr, ans, temp, target, i + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(candidates, ans, {}, target, 0);
        
        return ans;
    }
};