class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int left = -1;
        int right = -1;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(target > nums[mid])
                l = mid + 1;
            else
            {
                if(target == nums[mid])
                    left = mid;
                h = mid - 1;
            }
        }
        l = 0;
        h = n - 1;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(target < nums[mid])
                h = mid - 1;
            else
            {
                if(target == nums[mid])
                    right = mid;
                l = mid + 1;
            }
        }
        return {left, right};
    }
};