class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int h = 0;
        unordered_set<int> set;
        int ans = 0;
        int n = s.size();
        while(l < n && h < n)
        {
            if(set.find(s[h]) == set.end())
            {
                set.insert(s[h++]);
                ans = max(ans, h - l);
            }
            else
            {
                set.erase(s[l++]);
            }
        }
        return ans;
    }
};