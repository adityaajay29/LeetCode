class Solution {
public:
    int modulo = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        
        long long horMax = horizontalCuts[0];
        long long verMax = verticalCuts[0];
        
        for(int i=1;i<m;i++)
        {
            long long cut = horizontalCuts[i] - horizontalCuts[i - 1];
            horMax = max(horMax, cut);
        }
//         the size of last horizontal piece will be h - last cut index
        long long lastHorPiece = h - horizontalCuts[m - 1];
        horMax = max(horMax, lastHorPiece);
        
        for(int i=1;i<n;i++)
        {
            long long cut = verticalCuts[i] - verticalCuts[i - 1];
            verMax = max(verMax, cut);
        }
//         the size of last vertical piece will be w - last cut index
        long long lastVerPiece = w - verticalCuts[n - 1];
        verMax = max(verMax, lastVerPiece);
        
        long long cakeMax = (verMax * horMax);
        
        return cakeMax % modulo;
    }
};