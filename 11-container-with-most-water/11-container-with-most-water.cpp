class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int h=height.size()-1;
        int res=INT_MIN;
        int ans=0;
        while(l<h)
        {
            ans=min(height[h],height[l])*(h-l);
            res=max(res,ans);
            if(height[h]>height[l])
                l++;
            else 
                h--;
        }
        return res;
    }
};