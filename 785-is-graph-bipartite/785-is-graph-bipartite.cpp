class Solution {
public:
    bool dfs(vector<vector<int>> &list, vector<int> &color, int i)
    {
        for(int x : list[i])
        {
            if(color[x] == -1)
            {
                color[x] = 1 - color[i];
                if(dfs(list, color, x) == false)
                    return false;
            }
            else if(color[x] == color[i])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        for(int i=0;i<v;i++)
        {
            if(color[i] == -1)
            {
                color[i] = 1;
                if(dfs(graph, color, i) == false)
                    return false;
            }
        }
        return true;
    }
};