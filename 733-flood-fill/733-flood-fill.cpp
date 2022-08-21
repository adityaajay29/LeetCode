class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    
    bool isValid(vector<vector<int>> &grid, int x, int y, int &original, int m, int n)
    {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return false;
        
        if(grid[x][y] != original)
            return false;
        
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        
        if(original == color)
            return image;
        
        int m = image.size(), n = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color;
            for(int i=0;i<4;i++)
            {
                if(isValid(image, x + dx[i], y + dy[i], original, m, n))
                    q.push({x + dx[i], y + dy[i]});
            }
        }
        return image;
    }
};