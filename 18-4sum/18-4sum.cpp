class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target2 = target - (nums[i] + nums[j]);
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int twoSum = nums[left] + nums[right];
                    if(twoSum < target2)
                    {
                        left++;
                    }
                    else if(twoSum > target2)
                    {
                        right--;
                    }
                    else 
                    {
                        vector<int> temp{nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(temp);
                        while(left < right && nums[left] == temp[2])
                            left++;
                        while(left < right && nums[right] == temp[3])
                            right--;
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};