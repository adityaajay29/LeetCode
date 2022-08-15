class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int leader;
        int count = 0;
        for(int x : nums)
        {
            if(count == 0)
                leader = x;
            if(x == leader)
                count++;
            else
                count--;
        }
        count = 0;
        for(int x : nums)
            if(x == leader)
                count++;
        
        return (count > n / 2 ? leader : -1);
    }
};