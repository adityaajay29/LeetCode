class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp{intervals[0][0], intervals[0][1]};
        for(vector<int> v : intervals)
        {
            if(v[0] > temp[1])
            {
                ans.push_back(temp);
                temp = v;
            }
            else
                temp[1] = max(temp[1], v[1]);
        }
        ans.push_back(temp);
        return ans;
    }
};