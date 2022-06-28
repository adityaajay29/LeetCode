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
            if(set.find(freq) == set.end())
            {
                set.insert(freq);
            }
            else
            {
                int temp = freq;
                while(set.find(temp) != set.end())
                {
                    temp--;
                    del++;
                }
                if(temp != 0)
                {
                    set.insert(temp);
                }
            }
        }
        return del;
    }
};