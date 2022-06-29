class Solution {
public:
    static bool myComp(vector<int> &x, vector<int> &y)
    {
        return (x[0] == y[0] ? x[1] < y[1] : x[0] > y[0]);
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), myComp);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<people.size();i++)
        {
            int height = people[i][0];
            int count = people[i][1];
            ans.insert(ans.begin() + count, {height, count});
        }
        return ans;
    }
};