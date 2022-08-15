class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int target= 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            int newT = target - nums[i];
            int l = i + 1, h = n - 1;
            while(l < h)
            {
                int twoSum = nums[l] + nums[h];
                if(twoSum < newT)
                    l++;
                else if(twoSum > newT)
                    h--;
                else
                {
                    vector<int> temp{nums[i], nums[l], nums[h]};
                    ans.push_back(temp);
                    while(l <= h && nums[l] == temp[1])
                        l++;
                    while(l <= h && nums[h] == temp[2])
                        h--;
                }
            }
            while(i + 1 < n && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};