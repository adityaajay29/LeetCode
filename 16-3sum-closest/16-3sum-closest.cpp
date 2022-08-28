class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int l = i + 1, h = n - 1;
            while(l < h)
            {
                int twoSum = nums[l] + nums[h];
                if(twoSum + nums[i] == target)
                    return target;
                
//                 -23
//                 -8, -4, -2, -1, 1, 3, 3, 5, 9, 11
//                 o/p => -14
                
                if(abs(twoSum + nums[i] - target) < diff)
                {
                    ans = twoSum + nums[i];
                    diff = abs(twoSum + nums[i] - target);
                }
                if(twoSum + nums[i] > target)
                    h--;
                
                else
                    l++;
            }
        }
        return ans;
    }
};