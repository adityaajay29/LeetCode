class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0;
        int o = 0;
        int t = 0;
        for(int x : nums)
        {
            if(x == 0)
                z++;
            else if(x == 1)
                o++;
            else
                t++;
        }
        for(int i=0;i<z;i++)
        {
            nums[i] = 0;
        }
        for(int j = z;j<z+o;j++)
        {
            nums[j] = 1;
        }
        for(int k = o+z;k<z+o+t;k++)
        {
            nums[k] = 2;
        }
    }
};