class Solution {
public:
    bool solve(vector<int> &arr, vector<int> &visited, int target, int currSum, int i, int sides)
    {
        if(sides == 0)
            return true;
        
        if(currSum == target)
            return solve(arr, visited, target, 0, 0, sides - 1);
        
        for(int j=i;j<arr.size();j++)
        {
            if(!visited[j] && currSum + arr[j] <= target)
            {
                visited[j] = 1;
                if(solve(arr, visited, target, currSum + arr[j], j + 1, sides) == true)
                    return true;
                visited[j] = 0;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int x : matchsticks)
            sum += x;
        
        int n = matchsticks.size();
        
        if(sum % 4 || n < 4)
            return false;
        
        vector<int> visited(n, 0);
        return solve(matchsticks, visited, sum / 4, 0, 0, 3);
    }
};