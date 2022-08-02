class Solution {
public:
    int paliLen(string &s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return (right - left - 1);
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int even = paliLen(s, i, i + 1);
            int odd = paliLen(s, i, i);
            if(maxi < max(even ,odd))
            {
                maxi = max(even, odd);
                start = i - (maxi - 1) / 2;
            }
        }
        return s.substr(start, maxi);
    }
};