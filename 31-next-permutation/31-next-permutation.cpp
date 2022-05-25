class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
//         finding the point after which decreasing order starts
//         as decreasing order will not generate next permutation 
        for(i=n-1;i>=1;i--)
        {
            if(nums[i-1] < nums[i])
                break;
        }
//         array is in reverse order
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j;
//         finding the ele from last, just greater than the break point ele
        for(j=n-1;j>i-1;j--)
        {
            if(nums[j] > nums[i-1])
                break;
        }
//         even on swapping, the eles after break point will be in decreasing order
        swap(nums[j], nums[i-1]);
//         reverse after break point to get assending order, and hence the next perm
        reverse(nums.begin() + i, nums.end());
    }
};