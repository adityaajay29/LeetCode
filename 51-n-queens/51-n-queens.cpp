class Solution {
public:
    bool isValid(vector<string> &temp, int row, int col, int n)
    {
        int i = row;
        int j = col;
        while(i >= 0 && j >= 0)
        {
            if(temp[i][j] == 'Q')
                return false;
            
            i--;
            j--;
        }
        i = row;
        j = col;
        while(i < n && j >= 0)
        {
            if(temp[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        i = row;
        j = col;
        while(j >= 0)
        {
            if(temp[i][j] == 'Q')
                return false;
            
            j--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> temp, int col, int n)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(temp, row, col, n))
            {
                temp[row][col] = 'Q';
                solve(ans, temp, col + 1, n);
                temp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> temp(n, s);
        solve(ans, temp, 0, n);
        
        return ans;
    }
};