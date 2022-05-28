class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int temp = 0;
        for(int x : nums)
            temp += x;
        return sum - temp;
    }
};