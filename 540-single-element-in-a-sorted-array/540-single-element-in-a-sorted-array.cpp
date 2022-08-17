class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        while(l <= h)
        {
            if(l == h)
                return nums[l];
            
            int mid = l + (h - l) / 2;
            if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                return nums[mid];
            
            int lLen = mid - l;
            if(lLen % 2 == 0)
            {
                if(nums[mid - 1] == nums[mid])
                    h = mid;
                else
                    l = mid;
            }
            else
            {
                if(nums[mid - 1] == nums[mid])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};