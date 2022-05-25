class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> copy = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(copy[i][j] == 0)
                {
                    for(int k=0;k<m;k++)
                    {
                        matrix[k][j] = 0;
                    }
                    for(int k=0;k<n;k++)
                    {
                        matrix[i][k] = 0;
                    }
                }
            }
        }
    }
};