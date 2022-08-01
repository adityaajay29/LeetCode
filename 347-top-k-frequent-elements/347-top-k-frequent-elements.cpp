class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums)
        {
            mp[x]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        int i = 0;
        vector<int> ans;
        while(i < k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }
};