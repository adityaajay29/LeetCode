class Solution {
public:
    bool isVovel(char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int l = 0, h = n / 2;
        int c1, c2;
        c1 = c2 = 0;
        while(h < n)
        {
            if(isVovel(s[l++]))
                c1++;
            if(isVovel(s[h++]))
                c2++;
        }
        return c1 == c2;
    }
};