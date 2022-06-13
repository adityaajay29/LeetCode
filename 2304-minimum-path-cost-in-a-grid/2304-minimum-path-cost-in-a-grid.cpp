class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        vector<int> prev(n, 0);
        for(int j=0;j<n;j++)
        {
            prev[j] = grid[m-1][j];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            vector<int> curr(n, 0);
            for(int j=n-1;j>=0;j--)
            {
                int down = INT_MAX;
                for(int k=0;k<n;k++)
                {
                    int curr = moveCost[grid[i][j]][k] + prev[k];
                    down = min(curr, down);
                }
                curr[j] = grid[i][j] + down;
            }
            prev = curr;
        }
        for(int j=0;j<n;j++)
        {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};