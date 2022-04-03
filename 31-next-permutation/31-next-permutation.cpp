class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                break;
        }
//         if no smaller found, meaning the array is reverse sorted
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for(j=n-1;j>=i;j--)
        {
            if(nums[j]>nums[i-1])
                break;
        }
        swap(nums[j],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
    }
};