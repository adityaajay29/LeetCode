class Solution {
public:
    
    void rotateHelp(vector<int>& nums,int l,int h)
    {
        while(l<h)
        {
            swap(nums[l++],nums[h--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int l=k%n;
        rotateHelp(nums,0,n-l-1);
        rotateHelp(nums,n-l,n-1);
        rotateHelp(nums,0,n-1);
    }
};