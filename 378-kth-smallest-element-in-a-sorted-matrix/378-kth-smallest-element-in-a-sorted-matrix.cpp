class Solution {
public:
    int kthSmallest(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<m;i++)
        {
            pq.push({grid[i][0], {i, 0}});
        }
        int count = 1;
        while(!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(count == k)
                return val;
            
            count++;
            if(j + 1 < grid[i].size())
            {
                pq.push({grid[i][j + 1], {i, j + 1}});
            }
        }
        return -1;
    }
};