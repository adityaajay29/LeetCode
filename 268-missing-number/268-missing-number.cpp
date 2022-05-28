class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int numSum = 0;
        for(int x : nums)
            numSum += x;
        return sum - numSum;
    }
};