class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int p=nums[n-1];
        int l=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]%2==0)
            {
                l++;
                swap(nums[i],nums[l]);
            }
        }
        swap(nums[l+1],nums[n-1]);
        return nums;
    }
};