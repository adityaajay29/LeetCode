class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> list[n];
        for(int i=0;i<n;i++)
        {
            vector<int> a = points[i];
            for(int j=i + 1;j<n;j++)
            {
                vector<int> b = points[j];
                int x1 = a[0];
                int y1 = a[1];
                int x2 = b[0];
                int y2 = b[1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                list[i].push_back({j, dist});
                list[j].push_back({i, dist});
            }
        }
        vector<int> mst(n, 0);
        vector<int> distance(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();
            mst[curr] = 1;
            for(auto x : list[curr])
            {
                if(!mst[x.first])
                {
                    if(distance[x.first] > x.second)
                    {
                        distance[x.first] = x.second;
                        pq.push({distance[x.first], x.first});
                    }
                }
            }
        }
        int cost = 0;
        for(int x : distance)
            cost += x;
        
        return cost;
    }
};