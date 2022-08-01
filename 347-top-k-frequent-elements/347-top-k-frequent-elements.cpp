class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int x : nums)
            mp[x]++;
        
        for(auto x : mp)
        {
            bucket[x.second].push_back(x.first);
        }
        
        for(int i = n;i>=0;i--)
        {
            for(int x : bucket[i])
            {
                if(ans.size() == k)
                    break;
                
                ans.push_back(x);
            }
        }
        return ans;
    }
};