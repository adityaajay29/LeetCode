class Solution {
public:
    
    int dp[601][101][101];
    
    int helper(vector<pair<int, int>> &store, int m, int n, int sz)
    {
        if(sz == 0 || (n == 0 && m == 0))
            return 0;
        
        if(dp[sz][m][n] != -1)
            return dp[sz][m][n];
        
        if(store[sz-1].first > m || store[sz-1].second > n)
            return dp[sz][m][n] = helper(store, m, n, sz-1);
        
        int include = 1 + helper(store, m - store[sz-1].first, n - store[sz-1].second, sz-1);
        int exclude = helper(store, m, n, sz-1);
        
        return dp[sz][m][n] = max(include, exclude);
    }
     
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> store;
        for(string s : strs)
        {
            int count0 = 0;
            int count1 = 0;
            for(char c : s)
            {
                if(c == '0')
                    count0++;
                else 
                    count1++;
            }
            store.push_back({count0, count1});
        }
        memset(dp, -1, sizeof(dp));
        return helper(store, m, n, store.size());
    }
};