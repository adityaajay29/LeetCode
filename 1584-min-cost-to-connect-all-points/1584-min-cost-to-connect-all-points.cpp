// class Solution {
    
//     int rank[1001];
//     int parent[1001];
    
//     void makeSet(int n)
//     {
//         for(int i=0;i<n;i++)
//         {
//             rank[i]=0;
//             parent[i]=i;
//         }
//     }
    
//     int findParent(int x)
//     {
//         if(parent[x]==x)
//             return x;
//         return parent[x]=findParent(parent[x]);
//     }
    
//     void makeUnion(int x,int y)
//     {
//         int p1=findParent(x);
//         int p2=findParent(y);
//         if(rank[x]>rank[y])
//             parent[y]=p1;
//         else if(rank[y]>rank[x])
//             parent[x]=p2;
//         else
//         {
//             parent[y]=p1;
//             rank[x]++;
//         }
//     }
    
//     int kruskal(vector<vector<int>>& points,int &n)
//     {
//         vector<pair<int,pair<int,int>> >v;
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 int u=i;
//                 int v=j;
//                 int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
//                 v.push_back(make_pair(wt,make_pair(u,v)));
//             }
//         }
//         sort(v.begin(),v.end());
//         int cost=0;
//         for(auto x:v)
//         {
//             int wt=x.first;
//             int u=x.second.first;
//             int v=x.second.second;
//             int p1=findParent(u);
//             int p2=findParent(v);
//             if(p1!=p2)
//             {
//                 makeUnion(u,v);
//                 cost+=wt;
//             }
//         }
//         return cost;
//     }
    
//     public:
    
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n=points.size();
//         makeSet(n);
//         int cost=kruskal(points,n);
//         return cost;
//     }
// };



class Solution {
    
    vector<int> parent, size;
 
    int find(int v) {
        if(v == parent[v]){
            return v;
        }
        else{
            return parent[v] = find(parent[v]);
        }
    }

    
    int union_sets(int v1, int v2) {
        // Find parents of both vertices
        int p1 = find(v1);
        int p2 = find(v2);
        
        // If parents are different
        if(p1 != p2){
            if(size[p1] < size[p2]){
                swap(p1, p2);
            }
            
            // Update the parent of p2 as p1
            parent[p2] = p1;
            size[p1] += size[p2];
            return 1;
        }
        return 0;
    }

    // Convert the points into nodes of graph where distance between the nodes is the weight of the edge between the two nodes.
    // The minimum cost to make all points connected will be the same as cost of Minimum Spanning Tree (MST) of that graph.
    int MST(vector<vector<int>> points, int n) {
        parent.resize(n);
        size.resize(n);
        vector< pair<int, pair<int, int>> > edges;
        int i,j;
        // Store each possible pair of nodes and the distance between
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
               int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(make_pair(dist, make_pair(i, j)));
            }
        }
        
        // Sort all edges based on the weight
        sort(edges.begin(), edges.end());
        for(i=0 ; i<n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
        
        int min_cost = 0;
        for(auto e: edges){
            if(union_sets(e.second.first, e.second.second)){
                min_cost += e.first;
            }
        }
        
        return min_cost;
    }
    
    public: 
    int minCostConnectPoints(vector<vector<int>> points) {
        // Get the number of nodes/vertices in the graph
        int n = points.size();
        return MST(points, n);
        
    }
};