class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp;
        for(int x : nums)
        {
            if(x == 0)
                temp.push_back(0);
        }
        for(auto x: nums)
            if(x == 1)
                temp.push_back(1);
        for(auto x: nums)
            if(x == 2)
                temp.push_back(2);
        nums = temp;
    }
};