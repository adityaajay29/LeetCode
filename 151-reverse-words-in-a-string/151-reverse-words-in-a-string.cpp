class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int h = 0;
        int n = s.size();
        
        reverse(s.begin(), s.end());
        
        int i = 0;
        while(i < n)
        {
            while(i < n && s[i] != ' ')
            {
                s[h++] = s[i++];
            }
            if(l < h)
            {
                reverse(s.begin() + l, s.begin() + h);
                if(h == n)
                    break;
                s[h++] = ' ';
                l = h;
            }
            i++;
        }
        if(h > 0 && s[h - 1] == ' ')
            h--;
        s.resize(h);
            return s;
    }
};