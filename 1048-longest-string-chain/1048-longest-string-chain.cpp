class Solution {
public:
    static bool myComp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    
    bool isValid(string &s1, string &s2)
    {
        if(s1.size() - s2.size() != 1)
            return false;
        
        int i=0;
        int j=0;
        while(i < s1.size())
        {
            if(j < s2.size() && s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else i++;
        }
        return (i == s1.size() && j == s2.size());
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myComp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isValid(words[i], words[j]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};