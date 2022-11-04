class Solution {
public:
    bool isVovel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        int n = s.size(), l, h;
        l = 0, h = n - 1;
        while(l < h)
        {
            if(isVovel(s[l]) && isVovel(s[h]))
                swap(s[l++], s[h--]);
            else if(!isVovel(s[l]))
                l++;
            else if(!isVovel(s[h]))
                h--;
            else 
                l++, h--;
        }
        return s;
    }
};