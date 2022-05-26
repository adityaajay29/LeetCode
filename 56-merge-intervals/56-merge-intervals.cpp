class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
//         sort the intervals
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(vector<int> v : intervals)
        {
//             if they are not overlapping, temp will never overlap again
//             so push temp to ans, and make v as new temp
            if(v[0] > temp[1])
            {
                merged.push_back(temp);
                temp = v;
            }
            else
//                 merge temp and v
            {
                temp[1] = max(temp[1], v[1]);
            }
        }
//         at last put the left temp in ans
        merged.push_back(temp);
        return merged;
    }
};