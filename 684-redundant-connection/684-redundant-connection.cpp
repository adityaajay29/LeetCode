class Solution {
public:
    
    vector<int>list[10001];
    vector<int>ans;
    
    bool dfs(int u,int v,int parent)
    {
        if(u==v)
            return true;
        for(auto x:list[u])
        {
            if(x==parent)
                continue;
            if(dfs(x,v,u))
                return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>visited(n+1,0);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(dfs(u,v,-1))
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            else
            {
                list[u].push_back(v);
                list[v].push_back(u);
            }
        }
        return ans;
    }
};