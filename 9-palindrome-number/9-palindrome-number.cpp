class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if(s.size() == 0 || s.size() == 1)
            return true;
        
        int l = 0, h = s.size() - 1;
        while(l < h)
        {
            if(s[l] != s[h])
                return false;
            
            l++, h--;
        }
        return true;
    }
};