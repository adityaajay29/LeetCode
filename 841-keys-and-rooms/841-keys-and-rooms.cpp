class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>&visited,int i)
    {
        visited[i]=1;
        for(auto x:rooms[i])
        {
            if(!visited[x])
                dfs(rooms, visited, x);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(1001,0);
        dfs(rooms, visited, 0);
        for(int i=0;i<n;i++)
            if(visited[i]==0)
                return false;
        return true;
    }
};