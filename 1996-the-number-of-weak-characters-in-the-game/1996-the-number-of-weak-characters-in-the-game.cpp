class Solution {
public:
    static bool myComp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), myComp);
        
        int ans = 0;
        int currMax = INT_MIN;
        for(vector<int> v : properties)
        {
            if(v[1] < currMax)
                ans++;
            else
                currMax = v[1];
        }
        return ans;
    }
};