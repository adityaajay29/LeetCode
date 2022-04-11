class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > ans;
        ans=grid;
        while(k--)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=1;j<n;j++)
                {
                    ans[i][j]=grid[i][j-1];
                }
            }
            for(int i=0;i<m-1;i++)
            {
                ans[i+1][0]=grid[i][n-1];
            }
            ans[0][0]=grid[m-1][n-1];
            grid=ans;
        }
        return ans;
    }
};