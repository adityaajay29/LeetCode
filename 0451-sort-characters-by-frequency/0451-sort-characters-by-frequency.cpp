class Solution {
public:
    static bool myComp(pair<char, int> &a, pair<char, int> &b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        vector<pair<char, int>> temp;
        for(auto x : mp)
            temp.push_back({x.first, x.second});
        sort(temp.begin(), temp.end(), myComp);
        
        string ans = "";
        for(auto x : temp)
        {
            int i = 0;
            while(i++ < x.second)
                ans.push_back(x.first);
        }
        return ans;
    }
};