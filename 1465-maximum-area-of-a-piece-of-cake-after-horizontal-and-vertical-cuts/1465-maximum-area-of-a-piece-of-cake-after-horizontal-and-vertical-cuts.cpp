class Solution {
public:
    int modulo = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        vector<int> hor;
        vector<int> ver;
        
        hor.push_back(horizontalCuts[0]);
        ver.push_back(verticalCuts[0]);
        
        long long int horMax = hor[0];
        long long int verMax = ver[0];
        
        for(int i=1;i<m;i++)
        {
            int cut = horizontalCuts[i] - horizontalCuts[i - 1];
            hor.push_back(cut);
            horMax = max(horMax, (long long int)hor[i]);
        }
        hor.push_back(h - horizontalCuts[m - 1]);
        horMax = max(horMax, (long long int)hor[m]);
        
        for(int i=1;i<n;i++)
        {
            int cut = verticalCuts[i] - verticalCuts[i - 1];
            ver.push_back(cut);
            verMax = max(verMax, (long long int)ver[i]);
        }
        ver.push_back(w - verticalCuts[n - 1]);
        verMax = max(verMax, (long long int)ver[n]);
        
        long long int cakeMax = (verMax * horMax);
        
        return cakeMax % modulo;
    }
};