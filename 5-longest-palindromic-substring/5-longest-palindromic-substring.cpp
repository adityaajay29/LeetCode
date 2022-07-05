class Solution {
public:
    int palindromeLength(string &s, int i, int j)
    {
        int n = s.size();
        while(i >= 0 && j < n && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j - i - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)
            return s;
        
        int start = 0;
        int maxLen = 0;
        
        for(int i=0;i<n;i++)
        {
            int evenLength = palindromeLength(s, i, i + 1);
            int oddLength = palindromeLength(s, i, i);
            
            if(maxLen < max(evenLength, oddLength))
            {
                maxLen = max(evenLength, oddLength);
                start = i - (maxLen - 1)/2;
            }
        }
        return s.substr(start, maxLen);
    }
};