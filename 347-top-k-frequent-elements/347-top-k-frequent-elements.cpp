class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for(pair<int, int> x : mp)
        {
            bucket[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i = bucket.size() - 1;i >= 0;i--)
        {
            for(int x : bucket[i])
            {
                ans.push_back(x);
            }
            if(ans.size() == k)
                break;
        }
        return ans;
    }
};