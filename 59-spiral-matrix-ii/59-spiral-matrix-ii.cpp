class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n,0));
        int layer=(n+1)/2;
        int cnt=1;
        for(int j=0;j<layer;j++)
        {
            for(int i=j;i<n-j;i++)
            {
                v[j][i]=cnt++;
            }
            for(int i=j+1;i<(n-j);i++)
            {
                v[i][n-j-1]=cnt++;
            }
            for(int i=n-j-2;i>=j;i--)
            {
                v[n-j-1][i]=cnt++;
            }
            for(int i=n-j-2;i>j;i--)
            {
                v[i][j]=cnt++;
            }
        }
        return v;
    }
};