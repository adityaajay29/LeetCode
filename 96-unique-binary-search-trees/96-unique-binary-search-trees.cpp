class Solution {
public:
    int solve(int i, int n)
    {
        if(i == 0 || i == 1)
            return 1;
        
        if(i == 2)
            return 2;
        
        if(i == 3)
            return 5;
        
        int cut = 0;
        for(int k=0;k<n;k++)
        {
            cut += (solve(k, k) * solve(n - k - 1, n - k - 1)); 
        }
        return cut;
    }
    
    int numTrees(int n) {
        return solve(n, n);
    }
};