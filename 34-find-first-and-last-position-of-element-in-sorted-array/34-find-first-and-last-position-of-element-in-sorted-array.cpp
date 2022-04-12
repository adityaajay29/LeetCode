class Solution {
public:
    
    int findStart(vector<int>&nums,int target)
    {
        int index=-1;
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(target<=nums[mid])
            {
                h=mid-1;
            }
            else
                l=mid+1;
            if(target==nums[mid])
                index=mid;
        }
        return index;
    }
    
    int findEnd(vector<int>&nums,int target)
    {
        int index=-1;
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(target>=nums[mid])
            {
                l=mid+1;
            }
            else
                h=mid-1;
            if(target==nums[mid])
                index=mid;
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        ans[0]=findStart(nums,target);
        ans[1]=findEnd(nums,target);
        return ans;
    }
};