class Solution {
public:
    
    void dfs(string x, string y, double &val, map<string,int> &visited, map<string, double> &mp, map<string, vector<string> > &list, bool &flag)
    {
        visited[x]=1;
        for(string child:list[x])
        {
            if(visited[child]!=1)
            {
                val*=mp[x+"->"+child];
                if(child==y)
                {
                    flag=true;
                    return;
                }
                dfs(child,y,val,visited,mp,list,flag);
                if(flag==true)
                    return;
                else 
                    val/=mp[x+"->"+child];
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, double> mp;
        map<string, vector<string> > list;
        vector<double>ans;
        int n=values.size();
        for(int i=0;i<n;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++)
        {
            string x=queries[i][0];
            string y=queries[i][1];
            if(list.find(x)==list.end() || list.find(y)==list.end())
                ans.push_back(-1);
            else 
            {
                map<string,int>visited;
                double val=1;
                bool flag=false;
                if(x==y)
                {
                    flag=true;
                    ans.push_back(val);
                }
                else 
                {
                    dfs(x,y,val,visited,mp,list,flag);
                        if(flag==true)
                            ans.push_back(val);
                    else
                        ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};