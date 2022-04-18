class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=INT_MIN;
        vector<pair<int,int> >list[101];
        for(vector<int> &temp:times)
        {
            int u=temp[0];
            int v=temp[1];
            int time=temp[2];
            list[u].push_back({v,time});
        }
        // for(int i=1;i<=m;i++)
        // {
        //     for(auto x:list[i])
        //     {
        //         cout<<i<<" "<<x.first<<" "<<x.second;
        //     }
        //     cout<<endl;
        // }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >pq;
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        pq.push({distance[k],k});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
            if(dist>distance[curr])
                continue;
            for(auto x:list[curr])
            {
                if(distance[x.first]>dist+x.second)
                {
                    distance[x.first]=dist+x.second;
                    pq.push({distance[x.first],x.first});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,distance[i]);
        }
        for(int i=1;i<=n;i++)
            cout<<distance[i]<<" ";
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};