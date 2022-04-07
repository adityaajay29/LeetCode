class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        priority_queue<pair<int,int> >pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({arr[i],i});
        }
        return pq.top().second;
    }
};