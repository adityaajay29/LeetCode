class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int res=1;
            unordered_set<char>set;
            set.insert(s[i]);
            for(int j=i+1;j<s.size();j++)
            {
                if(set.find(s[j])==set.end())
                {
                    set.insert(s[j]);
                    res++;
                }
                else 
                {
                    break;
                }
            }
            ans=max(ans,res);
        }
        return ans;
    }
};