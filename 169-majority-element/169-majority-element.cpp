class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = NULL;
        int count = 0;
        for(int curr : nums)
        {
            if(count == 0)
            {
                candidate = curr;
            }
            if(curr == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};