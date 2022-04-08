class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int h=numbers.size()-1;
        vector<int>ans;
        while(l<h)
        {
            int sum=numbers[l]+numbers[h];
            if(sum==target)
            {
                ans.push_back(l+1);
                ans.push_back(h+1);
                return ans;
            }
            else if(target>sum)
                l++;
            else 
                h--;
        }
        return {};
    }
};