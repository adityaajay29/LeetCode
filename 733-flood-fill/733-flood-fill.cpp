class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, -1, 1};
    
    bool isValid(vector<vector<int>>& image, vector<vector<int>> &visited, int i,int j, int sr, int sc, int m, int n, int same)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if(visited[i][j] || image[i][j] != same)
            return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &image, vector<vector<int>> &visited, int x, int y, int sr, int sc, int m, int n, int same, int color)
    {
        visited[x][y] = 1;
        image[x][y] = color;
        for(int i=0;i<4;i++)
        { 
            if(isValid(image, visited, x + dx[i], y + dy[i], sr, sc, m, n, same))
            {
                dfs(image, visited, x + dx[i], y + dy[i], sr, sc, m, n, same, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n= image[0].size();
        int same = image[sr][sc];
        vector<vector<int>> visited(m, vector<int> (n, 0));
        dfs(image, visited, sr, sc, sr, sc, m, n, same, color);
        return image;
    }
};