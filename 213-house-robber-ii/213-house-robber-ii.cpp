class Solution {
public:
    int solve(vector<int> &arr, int i)
    {
        int twoPrev = 0;
        int prev = arr[0];
        
        for(int i=2;i<=arr.size();i++)
        {
            int take = arr[i - 1] + twoPrev;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            twoPrev = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> temp1, temp2;
        
        for(int i=0;i<n;i++)
        {
            if(i != n - 1)
                temp1.push_back(nums[i]);
            if(i != 0)
                temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1, n - 1), solve(temp2, n - 1)); 
    }
};