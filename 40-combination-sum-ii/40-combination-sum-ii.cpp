class Solution {
public:
    void solve(vector<int> &c, vector<vector<int>> &ans, vector<int> temp, int target, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<c.size();j++)
        {
            if(j != i && c[j] == c[j-1])
                continue;
            if(c[j] <= target)
            {
                temp.push_back(c[j]);
                solve(c, ans, temp, target - c[j], j+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        solve(candidates, ans, {}, target, 0);
        return ans;
    }
};