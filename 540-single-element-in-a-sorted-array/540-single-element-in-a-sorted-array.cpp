class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l <= h)
        {
            if(l == h)
                return nums[l];
            
            int mid = l + (h - l)/2;
            if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                return nums[mid];
            
            int lc = mid - l;
            int rc = h - mid;
            if(lc % 2 == 0)
            {
                if(nums[mid - 1] == nums[mid])
                    h = mid;
                else if(nums[mid + 1] == nums[mid])
                    l = mid;
            }
            else
            {
                if(nums[mid - 1] == nums[mid])
                    l = mid + 1;
                else if(nums[mid + 1] == nums[mid])
                    h = mid - 1;
            }
        }
        return -1;
    }
};