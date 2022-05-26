class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(auto v : intervals)
        {
            if(v[0] > temp[1])
            {
                ans.push_back(temp);
                temp = v;
            }
            else
            {
                temp[1] = max(temp[1], v[1]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};