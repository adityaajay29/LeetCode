class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 1 || n == 1)
            return true;
        
        for(int i = m - 1;i >= 0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i - 1 >= 0 && j - 1 >= 0)
                {
                    if(matrix[i - 1][j - 1] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};