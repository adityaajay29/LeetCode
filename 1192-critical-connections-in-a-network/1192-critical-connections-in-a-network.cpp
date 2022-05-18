class Solution {
    
public:
    
    void dfs(vector<int> list[], vector<vector<int>> &ans, int i, int parent, vector<int> &intime, vector<int> &low, vector<int> &visited, int timer)
    {
        visited[i]=1;
        intime[i]=timer;
        low[i]=timer++;
        for(auto x:list[i])
        {
//             if x is parent, do nothing
            if(x == parent)
                continue;
//             if x is ancestor, update the low time of i
            if(visited[x])
            {
                low[i]=min(low[i], intime[x]);
            }
//             if not visited, call dfs
            else
            {
                dfs(list, ans, x, i, intime, low, visited, timer);
//                 on returning, if the lowtime of x is more than intime of i, 
//                 means there was no ancestor 
                if(low[x] > intime[i])
                {
                    vector<int> bridge;
                    bridge.push_back(i);
                    bridge.push_back(x);
                    ans.push_back(bridge);
                }
//                 update the low time of i
                low[i]=min(low[i], low[x]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
//         making adj list
        vector<int> list[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        vector<int> intime(100001, INT_MAX);
        vector<int> low(100001, INT_MAX);
        vector<int> visited(100001, 0);
        
//         dfs for all the nodes
//         parent is initailised as -1
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(list, ans, i, -1, intime, low, visited, 1);
            }
        }
        return ans;
    }
};