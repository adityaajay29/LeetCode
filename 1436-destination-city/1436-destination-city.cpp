class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s1;
        unordered_set<string> s2;
        for(int i=0;i<paths.size();i++)
        {
            string u=paths[i][0];
            string v=paths[i][1];
            s1.insert(v);
            s2.insert(u);
        }
        for(auto x:s1)
        {
            if(s2.find(x) == s2.end())
                return x;
        }
        return "";
    }
};