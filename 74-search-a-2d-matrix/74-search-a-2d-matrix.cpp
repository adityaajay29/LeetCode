class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        if(target > matrix[m - 1][n - 1] || target < matrix[0][0])
            return false;
        
        while(i < m && j >= 0)
        {
            if(target == matrix[i][j])
                return true;
            
            if(target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};