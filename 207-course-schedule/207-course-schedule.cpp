class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> list[numCourses];
        for(int i=0;i<n;i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            list[u].push_back(v);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++)
        {
            for(int x : list[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        int topo = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo++;
            for(int x : list[curr])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return (topo == numCourses);
    }
};