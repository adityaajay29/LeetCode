class Solution {
public:
    
    void dfs(vector<int>list[],vector<int>&visited,int i)
    {
        visited[i]=1;
        for(auto x:list[i])
        {
            if(!visited[x])
                dfs(list,visited,x);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>list[n+1];
        vector<int>visited(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    list[i+1].push_back(j+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(list,visited,i);
            }
        }
        return count;
    }
};