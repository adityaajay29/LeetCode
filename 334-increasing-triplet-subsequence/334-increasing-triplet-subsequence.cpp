class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int candi1 = INT_MAX, candi2 = INT_MAX;
        for(int x : nums)
        {
            if(x <= candi1)
                candi1 = x;
            else if(x <= candi2)
                candi2 = x;
            else
                return true;
        }
        return false;
    }
};