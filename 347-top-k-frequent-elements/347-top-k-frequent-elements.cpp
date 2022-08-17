class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        
        vector<vector<int>> buckets(n + 1);
        vector<int> ans;
        for(auto x : mp)
        {
            buckets[x.second].push_back(x.first);
        }
        for(int i = n; i >= 0; i--)
        {
            for(int x : buckets[i])
            {
                if(ans.size() == k)
                    break;
                
                ans.push_back(x);
            }
        }
        return ans;
    }
};