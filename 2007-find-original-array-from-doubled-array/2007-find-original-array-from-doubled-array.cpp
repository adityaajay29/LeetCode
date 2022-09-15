class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if(changed.size() % 2)
            return {};
        
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        for(int x : changed)
            mp[x]++;
        
        for(int x : changed)
        {
            if(mp[x] == 0)
                continue;
            
            if(mp[x * 2] == 0)
                return {};
            
            ans.push_back(x);
            mp[x]--;
            mp[x * 2]--;
        }
        return ans;
    }
};