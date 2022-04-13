class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         ans will be max of ans and (h-l)
        int l=0;
        int h=0;
        int n=s.size();
//         ans will be zero for empty string
        int ans=0;
//         to keep track of uniqueness
        unordered_set<char>set;
        while(l<n && h<n)
        {
//             if unique, then add to set and increment the high pointer
            if(set.find(s[h])==set.end())
            {  
                set.insert(s[h++]);
                ans=max(ans,h-l);
            }
//             else, the character is repeated 
//             start updating from the left pointer
            else
            {
                set.erase(s[l++]);
            }
        }
        return ans;
    }
};