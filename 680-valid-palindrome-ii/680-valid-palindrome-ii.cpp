class Solution {
public:
    bool isPalindrome(string s,int l,int h)
    {
        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else 
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int h=s.size()-1;
        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else 
            {
                if(isPalindrome(s,l+1,h))
                    return true;
                else if(isPalindrome(s,l,h-1))
                    return true;
                else 
                    return false;
            }
        }
        return true;
    }
};