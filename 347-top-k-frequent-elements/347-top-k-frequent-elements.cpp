class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        int i = k;
        vector<int> ans;
        while(i--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};