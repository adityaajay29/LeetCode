class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        
        vector<int> asciiS(256);
        vector<int> asciiT(256);
        
        for(char c : s)
            asciiS[c]++;
        
        for(char c : t)
            asciiT[c]++;
        
        return (asciiS == asciiT);
    }
};