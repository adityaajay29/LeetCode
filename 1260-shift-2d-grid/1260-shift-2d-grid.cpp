class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
//         creating a temp grid for making changes
        vector<vector<int> > ans;
//         temp grid is same as given grid
        ans=grid;
//         running loop k times
        while(k--)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=1;j<n;j++)
                {
//                     shifting each row 1 column ahead
                    ans[i][j]=grid[i][j-1];
                }
            }
            for(int i=0;i<m-1;i++)
            {
//                 2nd operation
                ans[i+1][0]=grid[i][n-1];
            }
//             3rd aoperation
            ans[0][0]=grid[m-1][n-1];
//             since our new grid will be the temp grid, for multiple shifts, updating the given grid
            grid=ans;
        }
        return ans;
    }
};