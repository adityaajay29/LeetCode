class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x : arr)
            mp[x]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto x : mp)
            pq.push({x.second, x.first});
        
        int n = arr.size();
        int popped = 0, ans = 0;
        
        while(!pq.empty())
        {
            if(popped >= n / 2)
                break;
            
            popped += pq.top().first;
            pq.pop();
            ans++;
        }
        return ans;
    }
};