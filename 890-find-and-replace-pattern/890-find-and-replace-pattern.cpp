class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int sz = pattern.size();
        vector<string> ans;
        unordered_map<char, char> mp;
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            mp.clear();
            bool flag = true;
            for(int j=0;j<sz;j++)
            {
//                 if mapping present
                if(mp.find(pattern[j]) != mp.end())
                {
                    if(mp[pattern[j]] != s[j])
                    {
                        flag = false;
                        break;
                    }
                }
//                 if not present
                else
                {
                    for(auto x : mp)
                    {
                        if(x.second == s[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    mp[pattern[j]] = s[j];
                }
            }
            if(flag == true)
                ans.push_back(s);
        }
        return ans;
    }
};