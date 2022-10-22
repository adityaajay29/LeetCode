class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp; 
        for(auto c : t)
            mp[c]++; 
        int count = 0; 
        int low = 0, ans = INT_MAX, min_start = 0;     
        for(int high = 0; high < s.length(); high++) 
        {
            if(mp[s[high]] > 0) 
                count++; 
            mp[s[high]]--;  
            if(count == t.length()) 
            {
                while(low < high && mp[s[low]] < 0) 
                {
                    mp[s[low]]++;
                    low++; 
                }
                if(ans > high - low) 
                    ans = high - (min_start = low) + 1; 
                mp[s[low++]]++; 
                count--; 
            }
        }
        return ans == INT_MAX ? "" : s.substr(min_start, ans);
    }
};