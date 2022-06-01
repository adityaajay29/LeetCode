class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int target = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++)
        {
            int target2 = target - nums[i];
            int l = i+1;
            int h = n-1;
            while(l < h)
            {
                int twoSum = nums[l] + nums[h];
                if(target2 > twoSum)
                {
                    l++;
                }
                else if(target2 < twoSum)
                {
                    h--;
                }
                else
                {
                    vector<int> temp{nums[i], nums[l], nums[h]};
                    ans.push_back(temp);
                    l++;
                    h--;
                    while(l < h && nums[l] == temp[1])
                        l++;
                    while(l < h &&  nums[h] == temp[2])
                        h--;
                }
            }
            while(i + 1 < n && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};