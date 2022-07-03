class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        
        int up = 1;
        int down = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i - 1])
            {
                up = 1 + down;
            }
            else if(nums[i] < nums[i - 1])
            {
                down = 1 + up;
            }
        }
        return max(up, down);
    }
};