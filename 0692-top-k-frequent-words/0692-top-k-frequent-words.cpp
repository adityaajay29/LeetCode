class Solution {
public:
    
    static bool myComp(pair<string, int> &x, pair<string, int> &y)
    {
        return x.second == y.second ? x.first < y.first : x.second > y.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> bucket(n + 1);
        map<string, int> mp;
        for(string &s : words)
        {
            mp[s]++;
        }
        for(auto &x : mp)
        {
            bucket[x.second].push_back(x.first);
        }
        int count = 0;
        vector<pair<string, int>> ans;
        for(int i=n;i>=0;i--)
        {
            for(string &s : bucket[i])
            {
                if(count == k)
                    break;
                
                count++;
                ans.push_back({s, i});
            }
        }
        sort(ans.begin(), ans.end(), myComp);
        vector<string> res;
        for(auto &x : ans)
        {
            res.push_back(x.first);
        }
        return res;
    }
};