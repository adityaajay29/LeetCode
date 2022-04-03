class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
//         finding the first number from end such that nums[i]>nums[i-1]
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                break;
        }
//         if no smaller found, meaning the array is reverse sorted, so simply reverse it
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
//         now, all the elements are sorted in decreasing order (from i), as we already found a smaller ele, nums[i-1]
//         so, we will find a number just greater than nums[i-1]
        int j;
        for(j=n-1;j>=i;j--)
        {
            if(nums[j]>nums[i-1])
                break;
        }
//         swapped the just larger num with nums[i-1]
        swap(nums[j],nums[i-1]);
//         reverse the rest of the array after i-1, as this will give the lexicographically smallest permurtation
//         since the array after i-1 was reverse sorted
        reverse(nums.begin()+i,nums.end());
    }
};