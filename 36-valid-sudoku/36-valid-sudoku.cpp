class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>> &board, char num)
    {
        for(int i=0;i<9;i++)
        {
            if(i != row && board[i][col] == num)
                return false;
            
            if(i != col && board[row][i] == num)
                return false;
            
            int imgRow = 3 * (row / 3) + i / 3;
            int imgCol = 3 * (col / 3) + i % 3;
            
            if((imgRow != row && imgCol != col) && board[imgRow][imgCol] == num)
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    char num = board[i][j];
                    if(isValid(i, j, board, num) == false)
                        return false;
                }
            }
        }
        return true;
    }
};