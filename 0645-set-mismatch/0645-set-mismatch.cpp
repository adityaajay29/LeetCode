class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int a, b;
        set<int> s;
        int sum = 0;
        for(int x : nums)
        {
            sum += x;
            if(s.find(x) != s.end())
                a = x;
            
            s.insert(x);
        }
        sum -= a;
        int sum1 = 0;
        for(int i=1;i<=n;i++)
        {
            sum1 += i;
        }
        b = sum1 - sum;
        return {a, b};
    }
};