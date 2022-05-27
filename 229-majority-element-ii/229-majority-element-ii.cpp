class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int candidate1 = NULL;
        int candidate2 = NULL;
        int count1 = 0;
        int count2 = 0;
        for(int curr : nums)
        {
            if(curr == candidate1)
                count1++;
            else if(curr == candidate2)
                count2++;
            else if(count1 == 0)
            {
                candidate1 = curr;
                count1++;
            }
            else if(count2 == 0)
            {
                candidate2 = curr;
                count2++;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        int check1 = 0;
        int check2 = 0;
        for(int x : nums)
        {
            if(x == candidate1)
                check1++;
            else if(x == candidate2)
                check2++;
        }
        if(check1 > n/3)
            ans.push_back(candidate1);
        if(check2 > n/3)
            ans.push_back(candidate2);
        return ans;
    }
};