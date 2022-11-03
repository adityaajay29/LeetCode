class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0, notSame = 0;
        for(string &s : words)
        {
            if(s[0] == s[1])
            {
                if(mp[s])
                {
                    notSame--;
                    mp[s]--;
                    ans += 4;
                }
                else 
                {
                    mp[s]++;
                    notSame++;
                }
            }
            else 
            {
                string temp = s;
                reverse(temp.begin(), temp.end());
                if(mp[temp])
                {
                    mp[temp]--;
                    ans += 4;
                }
                else
                    mp[s]++;
            }
        }
        if(notSame)
            ans += 2;
        
        return ans;
    }
};