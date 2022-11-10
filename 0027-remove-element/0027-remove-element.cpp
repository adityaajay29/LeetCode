class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int l = 0, h = n - 1;
        while(l < h)
        {
            if(nums[h] == val)
                h--;
            else if(nums[l] == val)
                swap(nums[l++], nums[h--]);
            else 
                l++;
        }
        return nums[h] == val ? h : h + 1;
    }
};