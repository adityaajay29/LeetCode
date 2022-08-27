class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = INT_MIN;
        for(int c=0;c<col;c++)
        {
            vector<int> sums(row, 0);
            for(int j=c;j<col;j++)
            {
                for(int i=0;i<row;i++)
                {
                    sums[i] += matrix[i][j];
                }
                
                set<int> set;
                set.insert(0);
                int currSum = 0, currMax = INT_MIN;
                for(int x : sums)
                {
                    currSum += x;
                    auto it = set.lower_bound(currSum - k);
                    if(it != set.end())
                    {
                        currMax = max(currMax, currSum - *it);
                    }
                    set.insert(currSum);
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
};