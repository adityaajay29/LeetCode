class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int l =0;
        int h =n-1;
        int lmax =height[0];
        int rmax =height[n-1];
        int ans =0;
        while(l<h)
        {
            if(height[l] < height[h])
            {
                if(height[l] > lmax)
                    lmax = height[l];
                else
                    ans += lmax-height[l];
                l++;
            }
            else
            {
                if(height[h] > rmax)
                    rmax = height[h];
                else
                {
                    ans += rmax-height[h];
                }
                h--;
            }
        }
        return ans;
    }
};