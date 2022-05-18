class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> mp;
        unordered_set<string> s;
        for(int i=0;i<paths.size();i++)
        {
            string u=paths[i][0];
            string v=paths[i][1];
            mp[u].push_back(v);
            s.insert(v);
        }
        for(auto x:s)
        {
            if(mp.find(x) == mp.end())
                return x;
        }
        return "";
    }
};