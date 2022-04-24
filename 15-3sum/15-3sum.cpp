class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
//         sort nums
        sort(nums.begin(),nums.end());
        int n=nums.size();
//         corner case 1
        if(n<3)
            return {};
//         corner case 2
        if(nums[0]>0)
            return {};
//         itearting by fixing 1st num and so on
        for(int i=0;i<n;i++)
        {
//             escape same adj ele
            if(i>0 && nums[i]==nums[i-1])
                continue;
//             finding 3sum
            int l=i+1;
            int h=n-1;
            while(l<h)
            {
                if(nums[l] + nums[h] + nums[i]==0)
                {
                    vector<int>v{nums[l],nums[h],nums[i]};
                    ans.push_back(v);
//                     escape all duplicates
                    while(l<h && nums[l]==nums[l+1])
                    {
                        l++;
                    }
//                     escape all duplicates
                    while(l<h && nums[h]==nums[h-1])
                    {
                        h--;
                    }
//                     to look for next sets off unique eles
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h]+nums[i]<0)
                    l++;
                else 
                    h--;
            }
        }
        return ans;
    }
};