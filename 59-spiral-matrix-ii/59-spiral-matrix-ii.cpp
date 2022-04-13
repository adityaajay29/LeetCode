class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n,0));
        int layer=(n+1)/2;
        int cnt=1;
        for(int i=0;i<layer;i++)
        {
            for(int j=i;j<n-i;j++)
            {
                v[i][j]=cnt++;
            }
            for(int j=i+1;j<(n-i);j++)
            {
                v[j][n-i-1]=cnt++;
            }
            for(int j=n-i-2;j>=i;j--)
            {
                v[n-i-1][j]=cnt++;
            }
            for(int j=n-i-2;j>i;j--)
            {
                v[j][i]=cnt++;
            }
        }
        return v;
    }
};