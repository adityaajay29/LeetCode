class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        vector<int> prev(n + 1, 0);
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(n + 1, 0);
            for(int j=1;j<=n;j++)
            {
                if(s[i - 1] == s1[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else 
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        int lcs = prev[n];
        
        return n - lcs;
    }
};