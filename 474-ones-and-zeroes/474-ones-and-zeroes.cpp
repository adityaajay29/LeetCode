class Solution {
public:
    
    int dp[601][101][101];
    
    int helper(vector<pair<int, int>> &store, int m, int n, int i)
    {
        if(i == store.size() || (n == 0 && m == 0))
            return 0;
        
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        if(store[i].first > m || store[i].second > n)
            return dp[i][m][n] = helper(store, m, n, i+1);
        
        int include = 1 + helper(store, m - store[i].first, n - store[i].second, i+1);
        int exclude = helper(store, m, n, i+1);
        return dp[i][m][n] = max(include, exclude);
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
        return helper(store, m, n, 0);
    }
};