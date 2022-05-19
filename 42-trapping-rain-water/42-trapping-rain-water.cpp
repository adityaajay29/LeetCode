class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lh(n, 0);
        vector<int> rh(n, 0);
        lh[0] = height[0];
        rh[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        {
            lh[i] = max(height[i], lh[i-1]);
        }
        for(int j=n-2;j>=0;j--)
        {
            rh[j] = max(height[j], rh[j+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=abs(height[i] - min(lh[i], rh[i]));
        }
        return ans;
    }
};