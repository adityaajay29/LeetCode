class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        vector<pair<int, int>> points;
        for(vector<int> &v : buildings)
        {
            points.push_back({v[0], -v[2]});
            points.push_back({v[1], v[2]});
        }
        sort(points.begin(), points.end());
        
        int ongoing = 0;
        for(auto x : points)
        {
            int currPoint = x.first;
            int currHeight = x.second;
            if(currHeight < 0)
                pq.insert(-currHeight);
            else
                pq.erase(pq.find(currHeight));
            
            if(ongoing != *pq.rbegin())
            {
                ongoing = *pq.rbegin();
                ans.push_back({currPoint, ongoing});
            }
        }
        return ans;
    }
};