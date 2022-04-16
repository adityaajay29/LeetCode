class Solution {
public:
    unordered_map<string,vector<string> >mp;
    unordered_set<string>visited;
    void dfs(string &email,vector<string>&temp)
    {
        visited.insert(email);
        temp.push_back(email);
        for(auto x:mp[email])
        {
            if(visited.find(x)==visited.end())
                dfs(x,temp);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string> >ans;
        for(vector<string>v:accounts)
        {
            for(int i=2;i<v.size();i++)
            {
                mp[v[i]].push_back(v[i-1]);
                mp[v[i-1]].push_back(v[i]);
            }
        }
        
        for(vector<string>v:accounts)
        {
            if(visited.find(v[1])==visited.end())
            {
                vector<string>temp;
                temp.clear();
                temp.push_back(v[0]);
                dfs(v[1],temp);
                sort(temp.begin()+1,temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
};