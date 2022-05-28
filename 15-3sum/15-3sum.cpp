class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            int target2 = target - nums[i];
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                int twoSum = nums[left] + nums[right];
                if(twoSum < target2)
                    left++;
                else if(twoSum > target2)
                    right--;
                else 
                {
                    vector<int> temp{nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    while(left < right && nums[left] == temp[1])
                        left++;
                    while(left < right && nums[right] == temp[2])
                        right--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};