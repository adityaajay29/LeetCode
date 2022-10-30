class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> v;
        for(int i = 0; i < plantTime.size(); i++)
            v.push_back({growTime[i], plantTime[i]});
        
        sort(v.begin(), v.end());
        int res = 0;
        for (auto &x : v)
            res = max(res, x.first) + x.second;
        return res;
    }
};