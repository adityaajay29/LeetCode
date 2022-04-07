class Solution {
public:
//     bool dfs(vector<int>list[],vector<int>&visited,vector<int>&dfsVisited,int i)
//     {
//         visited[i]=1;
//         dfsVisited[i]=1;
//         for(auto x:list[i])
//         {
//             if(!visited[x])
//             {
//                 if(dfs(list,visited,dfsVisited,x))
//                     return true;
//             }
//             else if(dfsVisited[x])
//                 return true;
//         }
//         dfsVisited[i]=1;
//         return false;
//     }
    
//     bool cycleCheck(vector<int>list[],int numCourses)
//     {
//         vector<int>visited(numCourses,0);
//         vector<int>dfsVisited(numCourses,0);
//         for(int i=0;i<numCourses;i++)
//         {
//             if(!visited[i])
//             {
//                 if(dfs(list,visited,dfsVisited,i))
//                     return true;
//             }
//         }
//         return false;
//     }
    
    vector<int> bfs(vector<int>list[],vector<int>&topoSort,int numCourses)
    {
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto x:list[i])
                inDegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            topoSort.push_back(curr);
            for(auto x:list[curr])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(topoSort.size()==numCourses)
        return topoSort;
        return {};
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>list[numCourses];
        vector<int>topoSort;
        // bool isCycle=cycleCheck(list,numCourses);
        // cout<<isCycle<<endl;
        // else
        // {
            for(int i=0;i<prerequisites.size();i++)
            {
                int u=prerequisites[i][1];
                int v=prerequisites[i][0];
                list[u].push_back(v);
            }
        
        // for(int i=0;i<prerequisites.size();i++)
        // {
        //     for(auto x:list[i])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        
            return bfs(list,topoSort,numCourses);
        // }
    }
};