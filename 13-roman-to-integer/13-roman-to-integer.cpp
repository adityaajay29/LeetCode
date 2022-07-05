class Solution {
public:
    bool isSmaller(char &a, char &b)
    {
        return (a == 'I' && b == 'V' ||
                a == 'I' && b == 'X' ||
                a == 'X' && b == 'L' ||
                a == 'X' && b == 'C' ||
                a == 'C' && b == 'D' ||
                a == 'C' && b == 'M');
    }
    
    int value(char &a)
    {
        if(a == 'I')
            return 1;
        if(a == 'V')
            return 5;
        if(a == 'X')
            return 10;
        if(a == 'L')
            return 50;
        if(a == 'C')
            return 100;
        if(a == 'D')
            return 500;
        if(a == 'M')
            return 1000;
        return -1;
    }
    
    int romanToInt(string s) {
       int n = s.size();
        if(n == 1)
            return value(s[0]);
        
        int ans = 0;
        
        int i = 0;
        
        for(i=0;i<n-1;i++)
        {
            if(isSmaller(s[i], s[i + 1]))
            {
                ans += (value(s[i + 1]) - value(s[i]));
                i++;
            }
            else ans += value(s[i]);
        }
        if(i == n - 1)
            ans += value(s[n - 1]);
        return ans;
    }
};