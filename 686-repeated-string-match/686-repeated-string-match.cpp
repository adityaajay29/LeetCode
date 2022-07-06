class Solution {
public:
    bool isMatch(string &patt, string &text)
    {
        int k = patt.size();
        int n = text.size();
        for(int i=0;i<=n - k;i++)
        {
            if(text.substr(i, k) == patt)
                return true;
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        if(a == b)
            return 1;
        
        int count = 1;
        string patt = a;
        while(patt.size() < b.size())
        {
            patt += a;
            count++;
        }
        if(patt == b)
            return count;
        
        if(isMatch(b, patt))
            return count;
        
        patt += a;
        
        if(isMatch(b, patt))
            return count + 1;
        
        return -1;
    }
};