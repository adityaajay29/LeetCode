class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> arr = cuts;
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin(), arr.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz + 2, vector<int> (sz + 2, 0));
        for(int i=sz;i>=1;i--)
        {
            for(int j=1;j<=sz;j++)
            {
                int mini = INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    int part = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, part);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][sz];
    }
};