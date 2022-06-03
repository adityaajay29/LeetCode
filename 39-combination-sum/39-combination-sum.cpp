class Solution {
public:
    void solve(vector<int>& c, vector<vector<int>> &ans, vector<int> temp, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i == c.size())
            return;

        if(c[i] <= target)
        {
            temp.push_back(c[i]);
            solve(c, ans, temp, target - c[i], i);
            temp.pop_back();
        }
        solve(c, ans, temp, target, i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(candidates, ans, {}, target, 0);
        return ans;
    }
};