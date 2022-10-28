class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string &s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &x : mp)
        {
            vector<string> temp;
            for(string &s : x.second)
            {
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};