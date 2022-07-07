class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        
        vector<int> ascii(256);
        
        for(char c : s)
            ascii[c]++;
        
        for(char c : t)
            ascii[c]--;
        
        for(int x : ascii)
            if(x != 0)
                return false;
        
        return true;
    }
};