class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int h = 0;
        int count = 0;
        unordered_set<char> set;
        while(h < n)
        {
            if(set.find(s[h]) == set.end())
            {
                set.insert(s[h++]);
                count = max(count, h - l);
            }
            else
            {
                set.erase(s[l++]);
            }
        }
        return count;
    }
};