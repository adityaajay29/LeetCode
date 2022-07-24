class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;
        
        int i = 0;
        int j = n - 1;
        while(i < m && j >= 0)
        {
            if(target == matrix[i][j])
                return true;
            
            if(target > matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};