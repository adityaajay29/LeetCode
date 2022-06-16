class Solution {
public:
    int palindrome(string &s,int i, int j)
    {
        int l = i;
        int h = j;
        while(l >= 0 && h < s.size() && s[l] == s[h])
        {
            l--;
            h++;
        }
        return h - l - 1;
    }
    
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        
        int low = 0;
        int maxLen = 0;
        
        for(int i=0;i<s.size();i++)
        {
            int even = palindrome(s, i, i + 1);
            int odd = palindrome(s, i, i);
            if(maxLen < max(even, odd))
            {
                maxLen = max(even, odd);
                low = i - (maxLen - 1)/2;
            }
        }
        return s.substr(low, maxLen);
    }
};