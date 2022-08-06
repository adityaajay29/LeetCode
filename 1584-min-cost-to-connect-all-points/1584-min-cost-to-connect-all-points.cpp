class MST
{
    public : 
    int u, v, wt;
    MST(int i, int j, int k)
    {
        u = i;
        v = j;
        wt = k;
    }
};

class Solution {
public:
    static bool myComp(MST a, MST b)
    {
        return a.wt < b.wt;
    }
    
    int findParent(int a, vector<int> &parent)
    {
        if(parent[a] == a)
            return a;
         
        return parent[a] = findParent(parent[a], parent);
    }
    
    void makeUnion(int a, int b, vector<int> &ranked, vector<int> &parent)
    {
        a = findParent(a, parent);
        b = findParent(b, parent);
        
        if(ranked[a] > ranked[b])
            parent[b] = a;
        
        else if(ranked[b] > ranked[a])
            parent[a] = b;
        
        else
        {
            parent[a] = b;
            ranked[b]++;
        }
    }
    
    int kruskals(vector<MST> &list, vector<int> &parent, vector<int> &ranked)
    {
        int cost = 0;
        for(auto x : list)
        {
            int u = x.u;
            int v = x.v;
            int wt = x.wt;
            if(findParent(u, parent) != findParent(v, parent))
            {
                cost += wt;
                makeUnion(u, v, ranked, parent);
            }
        }
        return cost;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        vector<int> ranked(n, 0);
        vector<MST> list;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                vector<int> a = points[i];
                vector<int> b = points[j];
                int u = i;
                int v = j;
                int x1 = a[0];
                int x2 = b[0];
                int y1 = a[1];
                int y2 = b[1];
                int wt = abs(x1 - x2) + abs(y1 - y2);
                list.push_back({u, v, wt});
            }
        }
        sort(list.begin(), list.end(), myComp);
        return kruskals(list, parent, ranked);
    }
};