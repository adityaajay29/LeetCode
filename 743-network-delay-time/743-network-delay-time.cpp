class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n+1, INT_MAX);
        vector<pair<int, int>> list[n+1];
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            list[u].push_back({v, wt});
            // list[v].push_back({u, wt});
        }
        distance[k]=0;
        pq.push({0, k});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(wt>distance[node])
                continue;
            for(auto x:list[node])
            {
                if(distance[x.first]> wt+x.second)
                {
                    distance[x.first]=wt+x.second;
                    pq.push({distance[x.first], x.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1; i<=n;i++)
        {
            ans=max(ans, distance[i]);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
     }
};