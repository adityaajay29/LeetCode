class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int change = 0;
        while(i < n && change <= 1)
        {
            if(nums[i-1] > nums[i])
            {
                change++;
                if(i-2 < 0 || nums[i-2] <= nums[i])
                {
                    nums[i-1] = nums[i];
                }
                else
                    nums[i] = nums[i-1];
            }
            i++;
        }
        return change <= 1;
    }
};