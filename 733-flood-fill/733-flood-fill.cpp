class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    
    bool isValid(vector<vector<int>>& image, int i,int j, int sr, int sc, int m, int n, int &same)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(image[i][j] != same)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &image, int x, int y, int sr, int sc, int m, int n, int same, int color)
    {
        image[x][y] = color;
        for(int i=0;i<4;i++)
        { 
            if(isValid(image, x + dx[i], y + dy[i], sr, sc, m, n, same))
            {
                dfs(image, x + dx[i], y + dy[i], sr, sc, m, n, same, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n= image[0].size();
        int same = image[sr][sc];
        if(color != same)
            dfs(image, sr, sc, sr, sc, m, n, same, color);
        return image;
    }
};