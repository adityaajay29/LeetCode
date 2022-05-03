class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(), temp.end());
        int l=0;
        int h=n-1;
        int ans=n;
        while(l<h)
        {
            if(nums[l] != temp[l] && nums[h] != temp[h])
                return ans;
            if(nums[l] == temp[l])
            {
                ans--;
                l++;
            }
            if(nums[h] == temp[h])
            {
                ans--;
                h--;
            }
        }
        return 0;
    }
};