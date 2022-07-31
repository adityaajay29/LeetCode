class Solution {
public:
    void solve(vector<int> &candi, vector<vector<int>> &ans, vector<int> temp, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i == candi.size())
            return;
        
        if(candi[i] <= target)
        {
            temp.push_back(candi[i]);
            solve(candi, ans, temp, target - candi[i], i);
            temp.pop_back();
        }
        solve(candi, ans, temp, target, i + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(candidates, ans, {}, target, 0);
        return ans;
    }
};