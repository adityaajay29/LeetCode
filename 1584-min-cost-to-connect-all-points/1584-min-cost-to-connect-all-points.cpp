class Solution {
    public:
    
    struct mst
    {
        int u,v,wt;
        mst(int first, int second,int weight)
        {
            u=first;
            v=second;
            wt=weight;
        }
    };
    
    static bool myComp(mst a,mst b)
    {
        return a.wt<b.wt;
    }
    
    int findParent(int x,vector<int>&parent)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=findParent(parent[x],parent);
    }
    
    void makeUnion(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]>rank[v])
            parent[v]=u;
        else if(rank[v]>rank[u])
            parent[u]=v;
        else
        {
            parent[u]=v;
            rank[u]++;
        }
    }
    
    int kruskal(vector<mst>&list,vector<int>&parent,vector<int>&rank)
    {
        int cost=0;
        for(auto it : list) 
        {
            if(findParent(it.v, parent) != findParent(it.u, parent)) 
            {
                cost += it.wt; 
                makeUnion(it.u, it.v, parent, rank); 
            }
	    }
        return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>parent(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        vector<int>rank(n,0);
        vector<mst>list;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int u=i;
                int v=j;
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                list.push_back(mst(u,v,wt));
            }
        }
        sort(list.begin(),list.end(),myComp);
        int cost=kruskal(list,parent,rank);
        return cost;
    }
};