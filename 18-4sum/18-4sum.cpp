class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j = i + 1;j<n;j++)
            {
                long long newT = (long long)target - (long long)(nums[i] + nums[j]);
                int l = j + 1, h = n - 1;
                while(l < h)
                {
                    long long twoSum = nums[l] + nums[h];
                    if(twoSum > newT)
                        h--;
                    else if(twoSum < newT)
                        l++;
                    else
                    {
                        vector<int> temp{nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(temp);
                        while(l <= h && nums[l] == temp[2])
                            l++;
                        while(l <= h && nums[h] == temp[3])
                            h--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j])
                    j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};