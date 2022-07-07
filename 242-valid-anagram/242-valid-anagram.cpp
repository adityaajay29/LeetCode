class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        
        vector<int> ascii(26);
        
        for(int i=0;i<m;i++)
        {
            ascii[s[i] - 'a']++;
            ascii[t[i] - 'a']--;
        }
        
        for(int x : ascii)
            if(x != 0)
                return false;
        
        return true;
    }
};