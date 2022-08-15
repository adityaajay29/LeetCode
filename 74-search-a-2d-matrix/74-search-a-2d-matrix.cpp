class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = m * n - 1;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            int ix = mid / n;
            int iy = mid % n;
            int val = matrix[ix][iy];
            if(target == val)
                return true;
            
            if(target < val)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};