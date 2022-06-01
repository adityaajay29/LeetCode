class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
        vector<int> lMax(n, 0);
        vector<int> rMax(n, 0);
        lMax[0] = height[0];
        rMax[n-1] = height[n-1];
        
        for(int i=1;i<n;i++)
        {
            lMax[i] = max(height[i], lMax[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rMax[i] = max(height[i], rMax[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            ans += min(lMax[i], rMax[i]) - height[i];
        }
        return ans;
    }
};