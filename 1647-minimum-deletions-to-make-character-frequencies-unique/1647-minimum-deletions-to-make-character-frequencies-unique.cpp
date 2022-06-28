class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char x : s)
            mp[x]++;
        
        unordered_set<int> set;
        
        int del = 0;
        
        for(auto x : mp)
        {
            char c = x.first;
            int freq = x.second;
            while(set.find(freq) != set.end())
            {
                freq--;
                del++;
            }
            if(freq != 0)
            {
                set.insert(freq);
            }
        }
        return del;
    }
};